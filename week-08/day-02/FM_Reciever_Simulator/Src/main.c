#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

/* smaller the number higher the priority */

#define BUTTON_PRIORITY 2
#define TIMER_PRIORITY 4

GPIO_InitTypeDef volumeUp; //PA0
GPIO_InitTypeDef volumeDown; //PF10
GPIO_InitTypeDef channelUp; //PB4
GPIO_InitTypeDef channelDown; //PC7

UART_HandleTypeDef uart_handle;

TIM_HandleTypeDef transmit_timer;

typedef struct
{
    int volume;
    float channel;
} FM_Radio_t;

FM_Radio_t radio = {10, 87.5};
volatile uint32_t last_pressed = 0;
int press_delay = 150;//ms

short send_data = 1;

void init_buttons();
void init_uart();
void init_transmit_timer();
void transmit_data();
void loop_channel();

int main(void)
{
    HAL_Init();
    init_buttons();
    init_uart();
    init_transmit_timer();
    while (1) {
        if (send_data) {
            loop_channel();
            transmit_data();
        }
        HAL_Delay(1000);
    }
}

void loop_channel(){
    if(radio.channel > 108){
        radio.channel = 87.5;
    }
    if(radio.channel < 87.5){
        radio.channel = 108.0;
    }
}

void transmit_data()
{
    char volText[] = "Volume: ";
    char channelText[] = " | Channel: ";
    char volData[4] = "";
    char channelData[8] = "";

    sprintf(volData, "%d", radio.volume);
    sprintf(channelData, "%.1f\r\n", radio.channel);

    int outputLength = strlen(volText) + strlen(channelText) + strlen(volData) + strlen(channelData) + 1;
    char string[outputLength];

    strcpy(string, volText);
    strcat(string, volData);
    strcat(string, channelText);
    strcat(string, channelData);

    HAL_UART_Transmit(&uart_handle, (uint8_t*) string, outputLength - 1, 0xFFFF);
    send_data = 1;
}

void EXTI0_IRQHandler() //Volume up - 0
{
    //interrupt managment and callback
    HAL_GPIO_EXTI_IRQHandler(volumeUp.Pin);
}
void EXTI15_10_IRQHandler() //Volume down - 10
{
    //interrupt managment and callback
    HAL_GPIO_EXTI_IRQHandler(volumeDown.Pin);
}
void EXTI4_IRQHandler() //Channel up - 4
{
    //interrupt managment and callback
    HAL_GPIO_EXTI_IRQHandler(channelUp.Pin);
}
void EXTI9_5_IRQHandler() //Channel down - 7
{
    //interrupt managment and callback
    HAL_GPIO_EXTI_IRQHandler(channelDown.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    //check if is a valid button press
    uint32_t current_time = HAL_GetTick();
    if (current_time < last_pressed + press_delay) {
        return;
    }

    last_pressed = current_time;

    /* checking if the interrupt is from the correct pin */
    if (GPIO_Pin == volumeUp.Pin) {
        radio.volume++;
    } else if (GPIO_Pin == volumeDown.Pin) {
        radio.volume--;
    } else if (GPIO_Pin == channelUp.Pin) {
        radio.channel += 0.1;
    } else if (GPIO_Pin == channelDown.Pin) {
        radio.channel -= 0.1;
    }
}

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&transmit_timer);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM2) {

    }
}

void init_buttons()
{
    __HAL_RCC_GPIOA_CLK_ENABLE(); //volume up
    __HAL_RCC_GPIOB_CLK_ENABLE(); //channel up
    __HAL_RCC_GPIOC_CLK_ENABLE(); //channel down
    __HAL_RCC_GPIOF_CLK_ENABLE(); //volume down

    /* initialising */
    volumeUp.Pin = GPIO_PIN_0;
    volumeDown.Pin = GPIO_PIN_10;
    channelUp.Pin = GPIO_PIN_4;
    channelDown.Pin = GPIO_PIN_7;

    volumeUp.Pull = GPIO_NOPULL;
    volumeDown.Pull = GPIO_NOPULL;
    channelUp.Pull = GPIO_NOPULL;
    channelDown.Pull = GPIO_NOPULL;

    volumeUp.Speed = GPIO_SPEED_FAST;
    volumeDown.Speed = GPIO_SPEED_FAST;
    channelUp.Speed = GPIO_SPEED_FAST;
    channelDown.Speed = GPIO_SPEED_FAST;

    volumeUp.Mode = GPIO_MODE_IT_RISING;
    volumeDown.Mode = GPIO_MODE_IT_RISING;
    channelUp.Mode = GPIO_MODE_IT_RISING;
    channelDown.Mode = GPIO_MODE_IT_RISING;

    HAL_GPIO_Init(GPIOA, &volumeUp);
    HAL_GPIO_Init(GPIOB, &channelUp);
    HAL_GPIO_Init(GPIOC, &channelDown);
    HAL_GPIO_Init(GPIOF, &volumeDown);
    /* -------------------------------- */


    /* interrupt handling Setup */
    HAL_NVIC_SetPriority(EXTI0_IRQn, BUTTON_PRIORITY, 0);
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, BUTTON_PRIORITY, 0); //10
    HAL_NVIC_SetPriority(EXTI4_IRQn, BUTTON_PRIORITY, 0);
    HAL_NVIC_SetPriority(EXTI9_5_IRQn, BUTTON_PRIORITY, 0); //7

    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
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
    uart_handle.Init.Mode = UART_MODE_TX;

    BSP_COM_Init(COM1, &uart_handle);
}

void init_transmit_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    transmit_timer.Instance = TIM2;
    transmit_timer.Init.Prescaler = 54000;
    transmit_timer.Init.Period = 2000;
    transmit_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    transmit_timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&transmit_timer);

    HAL_NVIC_SetPriority(TIM2_IRQn, TIMER_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}
