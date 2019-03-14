#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

I2C_HandleTypeDef I2C_handle;

GPIO_InitTypeDef SCL_SDA_config;
UART_HandleTypeDef uart_handle;

TIM_HandleTypeDef read_timer;
TIM_HandleTypeDef display_timer;

#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define LED_MATRIX_ADDRESS  (0b1110000 << 1)

uint8_t temp_sensor_reg = 0;
uint8_t temp_sensor_val;

uint8_t system_setup_reg = 0x21;
uint8_t set_reg = 0xA0;
uint8_t display_set_reg = 0x81;

volatile int read_temp_flag = 0;
volatile int next_display_flag = 0;

int display_index = 0;

void i2c_init();
void uart_init();
void timer_init();
void fix_bits(uint8_t data[][8], int arraySize);
void parse_digits(int holderArray[], int number, int arraySize);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    i2c_init();
    uart_init();
    timer_init();

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

    int temperature_digits[3] = {0};

    while (1) {

        if (read_temp_flag) {
            HAL_I2C_Mem_Read(&I2C_handle,
                             TEMP_SENSOR_ADDRESS,
                             temp_sensor_reg,
                             I2C_MEMADD_SIZE_8BIT,
                             &temp_sensor_val,
                             sizeof(temp_sensor_val),
                             100);
            parse_digits(temperature_digits, temp_sensor_val, 3);
            read_temp_flag = 0;
            char string[5];
            sprintf(string, "%d\n", temp_sensor_val);
            HAL_UART_Transmit(&uart_handle, string, strlen(string), 0xFFFF);
        }
        if (next_display_flag) {
            for (int i = 0; i < 8; i++) {
                int numberToShow = temperature_digits[display_index];
                HAL_I2C_Mem_Write(&I2C_handle,
                                  LED_MATRIX_ADDRESS,
                                  i * 2,
                                  sizeof(uint8_t),
                                  &led_numbers[numberToShow][i],
                                  1,
                                  100);
            }
            display_index++;
            if (display_index > 2) {
                display_index = 0;
            }
            next_display_flag = 0;
        }
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

void parse_digits(int holderArray[], int number, int arraySize)
{
    int i = arraySize - 1;
    holderArray[i] = 10;
    i--;
    while (number) {
        holderArray[i] = number % 10;
        number /= 10;
        i--;
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
    __HAL_RCC_TIM3_CLK_ENABLE();

    read_timer.Instance = TIM2;
    display_timer.Instance = TIM3;
    read_timer.Init.Prescaler = 10800 - 1; //0.1ms
    display_timer.Init.Prescaler = 10800 - 1;
    read_timer.Init.Period = 20000 - 1; //2s
    display_timer.Init.Period = 6667 - 1;
    read_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    display_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    read_timer.Init.CounterMode = TIM_COUNTERMODE_UP;
    display_timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&read_timer);
    HAL_TIM_Base_Init(&display_timer);

/* Assign priority to interrupt line 15 lowest 0 highest */
    HAL_NVIC_SetPriority(TIM2_IRQn, 4, 0);
    HAL_NVIC_SetPriority(TIM3_IRQn, 4, 0);

/* Enable interrupt handler */

    HAL_NVIC_EnableIRQ(TIM2_IRQn);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);

    HAL_TIM_Base_Start_IT(&read_timer);
    HAL_TIM_Base_Start_IT(&display_timer);
}

void TIM2_IRQHandler()
{
    /* saving the current frame and executing the interrupt callback */
    HAL_TIM_IRQHandler(&read_timer);
}

void TIM3_IRQHandler()
{
    /* saving the current frame and executing the interrupt callback */
    HAL_TIM_IRQHandler(&display_timer);
}

/* interrupt callback*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    /* checking if the catched timer is the one we want to work with */
    if (htim->Instance == TIM2) {
        read_temp_flag = 1;
    } else if (htim->Instance == TIM3) {
        next_display_flag = 1;
    }
}