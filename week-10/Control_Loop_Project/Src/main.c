#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"
#include <string.h>

//UART
UART_HandleTypeDef uart_handle;
//ADC
//PWM TIMER
TIM_HandleTypeDef pwm;
GPIO_InitTypeDef pwm_pin;
//IC TIMER
TIM_HandleTypeDef ic_timer;
GPIO_InitTypeDef ic_pin;

void init_uart();
void init_pwm();
void init_ic();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_uart();
    init_pwm();
    init_ic();

    int fan_value = 100;
    int inc = -10;

    while (1) {
        __HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, fan_value);
        char string[50];
        sprintf(string, "%d\n", fan_value);
        HAL_UART_Transmit(&uart_handle,string,strlen(string),0xFFFF);
        fan_value += inc;
        HAL_Delay(2500);
        if(fan_value <= 0 || fan_value >= 100)
            inc = -inc;
    }
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
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);
}

void init_pwm()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    pwm_pin.Pin = GPIO_PIN_4;
    pwm_pin.Mode = GPIO_MODE_AF_PP;
    pwm_pin.Pull = GPIO_NOPULL;
    pwm_pin.Speed = GPIO_SPEED_HIGH;
    pwm_pin.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &pwm_pin);

    __HAL_RCC_TIM3_CLK_ENABLE();

    HAL_TIM_PWM_DeInit(&pwm);
    pwm.Instance = TIM3;
    pwm.Init.Prescaler = 108 - 1;
    pwm.Init.Period = 100 - 1;
    pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&pwm);

    TIM_OC_InitTypeDef pwm_config;

    pwm_config.Pulse = 20;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&pwm, &pwm_config, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&pwm, TIM_CHANNEL_1);
}

void init_ic()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    ic_timer.Instance = TIM2;
    ic_timer.Init.Prescaler = 0;
    ic_timer.Init.Period = UINT16_MAX;
    ic_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    ic_timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&ic_timer);

    HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    HAL_TIM_IC_Init(&ic_timer);

    TIM_IC_InitTypeDef ic_config;

    ic_config.ICPrescaler = TIM_ICPSC_DIV1;
    ic_config.ICSelection = TIM_ICSELECTION_DIRECTTI;
    ic_config.ICPolarity = TIM_ICPOLARITY_RISING;
    ic_config.ICFilter = 0;

    HAL_TIM_IC_ConfigChannel(&ic_timer, &ic_config, TIM_CHANNEL_1);



    //HAL_TIM_Base_Start_IT(&ic_timer);
    HAL_TIM_IC_Start_IT(&ic_timer, TIM_CHANNEL_1);


    __HAL_RCC_GPIOA_CLK_ENABLE();

    ic_pin.Pin = GPIO_PIN_15;
    ic_pin.Mode = GPIO_MODE_AF_OD;
    ic_pin.Pull = GPIO_NOPULL;
    ic_pin.Speed = GPIO_SPEED_HIGH;
    ic_pin.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &ic_pin);
}

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&ic_timer);
}

/* interrupt callback*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2){
    }
}