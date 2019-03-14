#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

I2C_HandleTypeDef I2C_handle;

GPIO_InitTypeDef SCL_SDA_config;
UART_HandleTypeDef uart_handle;

TIM_HandleTypeDef timer;

#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define LED_MATRIX_ADDRESS  (0b1110000 << 1)

uint8_t temp_sensor_reg = 0;
uint8_t temp_sensor_val;

uint8_t system_setup_reg = 0x21;
uint8_t set_reg = 0xA0;
uint8_t display_set_reg = 0x81;
void i2c_init();
void uart_init();
void timer_init();
void fix_bits(uint8_t data[][8], int arraySize);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    i2c_init();
    uart_init();
    //timer_init();

    uint8_t led_numbers[][8] =
        {{0x00, 0x00, 0x7e, 0x81, 0x81, 0x81, 0x7e, 0x00}, //0
         {0x00, 0x00, 0x21, 0x41, 0xff, 0x01, 0x01, 0x00}, //1
         {0x00, 0x00, 0x41, 0x83, 0x85, 0x89, 0x71, 0x00}, //2
         {0x00, 0x00, 0x42, 0x81, 0x91, 0x91, 0x6e, 0x00}, //3
         {0x00, 0x0c, 0x14, 0x24, 0x44, 0xff, 0x04, 0x00}, //4
         {0x00, 0x00, 0xf2, 0x91, 0x91, 0x91, 0x8e, 0x00}, //5
         {0x00, 0x00, 0x7e, 0x91, 0x91, 0x91, 0x4e, 0x00}, //6
         {0x00, 0x00, 0x80, 0x87, 0x88, 0x90, 0xe0, 0x00}, //7
         {0x00, 0x00, 0x6e, 0x91, 0x91, 0x91, 0x6e, 0x00}, //8
         {0x00, 0x00, 0x72, 0x89, 0x89, 0x89, 0x7e, 0x00}, //9
         {0x00, 0xc0, 0xc0, 0x1e, 0x21, 0x21, 0x21, 0x00}}; //°c

    fix_bits(led_numbers, 11);

    HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &system_setup_reg, sizeof(system_setup_reg), 100);
    HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &set_reg, sizeof(set_reg), 100);
    HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &display_set_reg, sizeof(display_set_reg), 100);

    int j = 0;
    while (1) {
        for (int i = 0; i < 8; i++) {
            HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, i*2, sizeof(uint8_t), &led_numbers[j][i], 1, 100);
        }

        HAL_I2C_Mem_Read(&I2C_handle,
                         TEMP_SENSOR_ADDRESS,
                         temp_sensor_reg,
                         I2C_MEMADD_SIZE_8BIT,
                         &temp_sensor_val,
                         sizeof(temp_sensor_val),
                         100);
        char string[5];
        sprintf(string, "%d\n", temp_sensor_val);
        HAL_UART_Transmit(&uart_handle, string, strlen(string), 0xFFFF);

        j++;
        if(j > 10)
            j = 0;
        HAL_Delay(1000);
    }
}

void fix_bits(uint8_t data[][8], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < 8; j++) {
            uint8_t LSB = data[i][j] & 1;
            LSB = LSB << 7;
            data[i][j] = data[i][j] >> 1;
            data[i][j] |= LSB;
        }
    }
}

void i2c_init()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    SCL_SDA_config.Pin = GPIO_PIN_8 | GPIO_PIN_9; // SCL: PB8 | SDA: PB9
    SCL_SDA_config.Pull = GPIO_PULLUP;
    SCL_SDA_config.Mode = GPIO_MODE_AF_OD;
    SCL_SDA_config.Alternate = GPIO_AF4_I2C1;

    HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

    __HAL_RCC_I2C1_CLK_ENABLE();

    I2C_handle.Instance = I2C1;
    I2C_handle.Init.Timing = 0x40912732;
    I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

    HAL_I2C_Init(&I2C_handle);
}

void uart_init()
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

void timer_init()
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