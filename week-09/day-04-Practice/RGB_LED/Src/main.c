#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

UART_HandleTypeDef UartHandle;

TIM_HandleTypeDef red_pwm;
TIM_HandleTypeDef blue_pwm;
TIM_HandleTypeDef green_pwm;

GPIO_InitTypeDef red_led;
GPIO_InitTypeDef blue_led;
GPIO_InitTypeDef green_led;

GPIO_InitTypeDef joystick;

ADC_HandleTypeDef adc_handle;

void init_pwm();
void init_leds();
void init_adc();
void init_uart();

double lerp(double numToMap, double numMinVal, double numMaxVal, double targetMinVal, double targetMaxVal)
{
    return ((((numToMap - numMinVal) * (targetMaxVal - targetMinVal)) / (numMaxVal - numMinVal)) + targetMinVal);
}

int main(void)
{
    srand(time(0));
    HAL_Init();
    SystemClock_Config();
    init_pwm();
    init_leds();

    init_adc();
    init_uart();

    int xVal = 0;
    int yVal = 0;
    char string[20];
    while (1) {
        HAL_ADC_Start(&adc_handle);
        if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            xVal = HAL_ADC_GetValue(&adc_handle);
            //xVal = (int) lerp(xVal, 0, 4095, -50, 50);
        }
        /*if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            yVal = HAL_ADC_GetValue(&adc_handle);
            yVal = (int) lerp(xVal, 0, 4095, -50, 50);
        }*/
        switch (rand() % 3) {
            case 0: __HAL_TIM_SET_COMPARE(&green_pwm, TIM_CHANNEL_1, rand() % 101);
                break;

            case 1: __HAL_TIM_SET_COMPARE(&red_pwm, TIM_CHANNEL_2, rand() % 101);
                break;

            case 2: __HAL_TIM_SET_COMPARE(&blue_pwm, TIM_CHANNEL_1, rand() % 101);
                break;

            default: break;
        }
        HAL_Delay(20);

        sprintf(string, "X: %d Y: %d\n", xVal, yVal);
        HAL_UART_Transmit(&UartHandle, string, strlen(string), 0xFFFF);
        HAL_Delay(100);
        HAL_ADC_Stop(&adc_handle);
    }
}

void init_pwm()
{
    __HAL_RCC_TIM12_CLK_ENABLE();
    red_pwm.Instance = TIM12;
    red_pwm.Init.Prescaler = 108 - 1;
    red_pwm.Init.Period = 100 - 1;
    red_pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    red_pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&red_pwm);

    __HAL_RCC_TIM1_CLK_ENABLE();
    blue_pwm.Instance = TIM1;
    blue_pwm.Init.Prescaler = 108 - 1;
    blue_pwm.Init.Period = 100 - 1;
    blue_pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    blue_pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&blue_pwm);

    __HAL_RCC_TIM2_CLK_ENABLE();
    green_pwm.Instance = TIM2;
    green_pwm.Init.Prescaler = 108 - 1;
    green_pwm.Init.Period = 100 - 1;
    green_pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    green_pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&green_pwm);

    TIM_OC_InitTypeDef config;

    config.Pulse = 0;
    config.OCMode = TIM_OCMODE_PWM1;
    config.OCPolarity = TIM_OCPOLARITY_HIGH;
    config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&red_pwm, &config, TIM_CHANNEL_2);
    HAL_TIM_PWM_ConfigChannel(&blue_pwm, &config, TIM_CHANNEL_1);
    HAL_TIM_PWM_ConfigChannel(&green_pwm, &config, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&red_pwm, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&blue_pwm, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&green_pwm, TIM_CHANNEL_1);

}

void init_leds()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    red_led.Pin = GPIO_PIN_15;
    red_led.Mode = GPIO_MODE_AF_OD;
    red_led.Pull = GPIO_NOPULL;
    red_led.Alternate = GPIO_AF9_TIM12;
    HAL_GPIO_Init(GPIOB, &red_led);

    __HAL_RCC_GPIOA_CLK_ENABLE();
    blue_led.Pin = GPIO_PIN_8;
    blue_led.Mode = GPIO_MODE_AF_OD;
    blue_led.Pull = GPIO_NOPULL;
    blue_led.Alternate = GPIO_AF1_TIM1;
    HAL_GPIO_Init(GPIOA, &blue_led);

    green_led.Pin = GPIO_PIN_15;
    green_led.Mode = GPIO_MODE_AF_OD;
    green_led.Pull = GPIO_NOPULL;
    green_led.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &green_led);
}

void init_adc()
{
    __HAL_RCC_GPIOF_CLK_ENABLE();
    joystick.Pin = GPIO_PIN_10;
    joystick.Mode = GPIO_MODE_ANALOG;
    joystick.Speed = GPIO_SPEED_FAST;
    joystick.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOF, &joystick);

    joystick.Pin = GPIO_PIN_9;
    HAL_GPIO_Init(GPIOF, &joystick);

    __HAL_RCC_ADC3_CLK_ENABLE();

    adc_handle.Instance = ADC3;
    adc_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
    adc_handle.Init.ContinuousConvMode = ENABLE;
    adc_handle.Init.NbrOfConversion = 2;
    HAL_ADC_Init(&adc_handle);

    ADC_ChannelConfTypeDef adc_channel_config;

    adc_channel_config.Channel = ADC_CHANNEL_8;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    adc_channel_config.Rank = 0;
    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

    adc_channel_config.Channel = ADC_CHANNEL_7;
    adc_channel_config.Rank = 1;
    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void init_uart()
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