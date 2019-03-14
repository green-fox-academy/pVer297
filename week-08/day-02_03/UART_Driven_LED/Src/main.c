#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

TIM_HandleTypeDef timer;

GPIO_InitTypeDef LED;

UART_HandleTypeDef uart_handle;

#define BUFFER_SIZE 10
char user_input[BUFFER_SIZE] = "";
char currentChar;

void init_timer();
void init_ext_led();
void init_uart();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_ext_led();
    init_timer();
    init_uart();
    BSP_LED_Init(LED1);

    HAL_UART_Receive_IT(&uart_handle, &currentChar, 1);
    while (1) {
    }
}

void TIM2_IRQHandler()
{
    /* saving the current frame and executing the interrupt callback */
    HAL_TIM_IRQHandler(&timer);
}

/* interrupt callback*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    /* checking if the catched timer is the one we want to work with */
    if (htim->Instance == TIM2) {
        HAL_GPIO_TogglePin(GPIOF, LED.Pin);
    }
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler(&uart_handle);
}

/* interrupt callback on uart recieve*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if (huart->Instance == USART1) {
        if (currentChar != '\n' && currentChar != '\r' && (strlen(user_input) + 1) < BUFFER_SIZE) {
            strcat(user_input, &currentChar);
        } else {
            if (strcmp(user_input, "flash") == 0) {
                HAL_TIM_Base_Start_IT(&timer);
                memset(user_input, '\0', BUFFER_SIZE);
            } else if (strcmp(user_input, "on") == 0) {
                HAL_TIM_Base_Stop_IT(&timer);
                HAL_GPIO_WritePin(GPIOF, LED.Pin, 1);
                memset(user_input, '\0', BUFFER_SIZE);
            } else if (strcmp(user_input, "off") == 0) {
                HAL_TIM_Base_Stop_IT(&timer);
                HAL_GPIO_WritePin(GPIOF, LED.Pin, 0);
                memset(user_input, '\0', BUFFER_SIZE);
            } else {
                memset(user_input, '\0', BUFFER_SIZE);
            }
        }

        HAL_UART_Receive_IT(&uart_handle, &currentChar, 1);
    }
}

void init_timer()
{
//TIM2-TIM3 general purpose timers
    __HAL_RCC_TIM2_CLK_ENABLE();
    timer.Instance = TIM2;
    timer.Init.Prescaler = 5400 - 1; //0.5ms
    timer.Init.Period = 10000 - 1; //0.5s
    timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer);

/* Assign priority to interrupt line 15 lowest 0 highest */
    HAL_NVIC_SetPriority(TIM2_IRQn, 4, 0);

/* Enable interrupt handler */

    HAL_NVIC_EnableIRQ(TIM2_IRQn);
    HAL_TIM_Base_Start_IT(&timer);
}

void init_ext_led()
{
    __HAL_RCC_GPIOF_CLK_ENABLE();

    LED.Pin = GPIO_PIN_10;
    LED.Mode = GPIO_MODE_OUTPUT_PP;
    LED.Pull = GPIO_NOPULL;
    LED.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOF, &LED);
}

void init_uart()
{
    __HAL_RCC_USART1_CLK_ENABLE();

    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_RX;

    BSP_COM_Init(COM1, &uart_handle);

    HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
}