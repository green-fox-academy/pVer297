#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

UART_HandleTypeDef UartHandle;

GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

TIM_HandleTypeDef TimHandle;
TIM_OC_InitTypeDef sConfig;
GPIO_InitTypeDef LED;

int adc_val;

double lerp(double numToMap, double numMinVal, double numMaxVal, double targetMinVal, double targetMaxVal)
{
    return ((((numToMap - numMinVal) * (targetMaxVal - targetMinVal)) / (numMaxVal - numMinVal)) + targetMinVal);
}

void uart_init();
void adc_init();
void led_init();
void timer_init();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    uart_init();
    adc_init();
    led_init();
    timer_init();

    while (1) {
        HAL_Delay(500);
        HAL_ADC_Start(&adc_handle);
        if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            adc_val = HAL_ADC_GetValue(&adc_handle);
            adc_val = (int) lerp(adc_val, 0, 4095, 0, 100);
            char string[10];
            sprintf(string, "%d\n", adc_val);
            HAL_UART_Transmit(&UartHandle, string, strlen(string), 0xFFFF);
        }
        __HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, adc_val);
    }
}

void uart_init()
{
    __HAL_RCC_USART1_CLK_ENABLE();
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    BSP_COM_Init(COM1, &UartHandle);
}

void adc_init()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_0;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    HAL_ADC_Init(&adc_handle);

    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void led_init()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    LED.Speed = GPIO_SPEED_FAST;
    LED.Pull = GPIO_NOPULL;
    LED.Pin = GPIO_PIN_15;
    LED.Mode = GPIO_MODE_AF_PP;
    LED.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &LED);
}

void timer_init()
{
    __HAL_RCC_TIM2_CLK_ENABLE();
    TimHandle.Instance = TIM2;
    TimHandle.Init.Prescaler = 108 - 1;    /* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    TimHandle.Init.Period = 100 - 1;    /* 100 x 0.001 ms = 10 ms = 0.01 s period */
    TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&TimHandle);

    sConfig.Pulse = 50;

    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
}