#include <string.h>
#include <math.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

/* smaller the number higher the priority */

#define BUTTON_PRIORITY 2

GPIO_InitTypeDef volumeUp; //PA0
GPIO_InitTypeDef volumeDown; //PF10
GPIO_InitTypeDef channelUp; //PB4
GPIO_InitTypeDef channelDown; //PC7

UART_HandleTypeDef uart_handle;

typedef enum
{
    FM_BAND_START = 875,
    INFO_FM = 881,
    MUSIC_FM = 895,
    JAZZY_FM = 909,
    CLASSIC_FM = 921,
    CLUB_FM = 929,
    FM_BAND_END = 1080
} Saved_Channels;

typedef struct
{
    int volume;
    float channel;
} FM_Radio_t;

FM_Radio_t radio = {10, 87.5};

volatile uint32_t last_pressed = 0;
int press_delay = 50;//ms

volatile uint32_t press_start = 0;

short send_data = 0;

void init_buttons();
void init_uart();
void transmit_data();
void loop_channel();
char* getChannelName(float channel);
float findCh(int state);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_buttons();
    init_uart();
    while (1) {
        if (send_data) {
            transmit_data();
        }
    }
}

void loop_channel()
{
    if (radio.channel > 108) {
        radio.channel = 87.5;
    }
    if (radio.channel < 87.5) {
        radio.channel = 108.0;
    }
}

void transmit_data()
{
    char volText[] = "Volume: ";
    char channelText[] = " | Channel: ";
    char volData[4] = "";
    char channelData[6] = "";
    char channelName[20] = "";

    sprintf(volData, "%d", radio.volume);
    sprintf(channelData, "%.1f", radio.channel);
    sprintf(channelName, " | %s\r\n", getChannelName(radio.channel));

    int outputLength =
        strlen(volText) + strlen(channelText) + strlen(volData) + strlen(channelData) + strlen(channelName) + 1;
    char string[outputLength];

    strcpy(string, volText);
    strcat(string, volData);
    strcat(string, channelText);
    strcat(string, channelData);
    strcat(string, channelName);

    HAL_UART_Transmit(&uart_handle, (uint8_t*) string, strlen(string), 0xFFFF);
    send_data = 0;
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
    //check if edge is rising on button
    int isRising = HAL_GPIO_ReadPin(GPIOA, volumeUp.Pin) ||
        HAL_GPIO_ReadPin(GPIOC, channelDown.Pin) ||
        HAL_GPIO_ReadPin(GPIOB, channelUp.Pin) ||
        HAL_GPIO_ReadPin(GPIOF, volumeDown.Pin);

    //check if is a valid button press
    uint32_t current_time = HAL_GetTick();
    if (current_time < last_pressed + press_delay)
        return;

    last_pressed = current_time;

    if (isRising) {
        press_start = HAL_GetTick();
        return;
    } else {
        uint32_t press_time = HAL_GetTick() - press_start;
        int vol;
        float ch;
        if (press_time > 1000) {
            ch = 0;
            vol = 5;
        } else {
            vol = 1;
            ch = 0.1;
        }
        /* checking if the interrupt is from the correct pin */
        if (GPIO_Pin == volumeUp.Pin && radio.volume < 100) {
            radio.volume += vol;
        } else if (GPIO_Pin == volumeDown.Pin && radio.volume > 0) {
            radio.volume -= vol;
        } else if (GPIO_Pin == channelUp.Pin) {
            if (ch == 0) {
                radio.channel = findCh(1);
            } else {
                radio.channel += ch;
            }
        } else if (GPIO_Pin == channelDown.Pin) {
            if (ch == 0) {
                radio.channel = findCh(0);
            } else {
                radio.channel -= ch;
            }
        }
    }

    loop_channel();
    send_data = 1;
}

float findCh(int state)
{
    if (state == 1) {//nextCh
        for (int i = (int) round(radio.channel * 10 + 1); i < FM_BAND_END; i++) {
            if (strcmp(getChannelName((float) i / 10), "No signal") != 0) {
                return (float) i / 10;
            }
        }
        for (int i = FM_BAND_START; i < (int) round(radio.channel * 10 - 1); i++) {
            if (strcmp(getChannelName((float) i / 10), "No signal") != 0) {
                return (float) i / 10;
            }
        }
    } else { //prevCh
        for (int i = (int) round(radio.channel * 10 - 1); i > FM_BAND_START; i--) {
            if (strcmp(getChannelName((float) i / 10), "No signal") != 0) {
                return (float) i / 10;
            }
        }
        for (int i = FM_BAND_END; i > (int) round(radio.channel * 10 + 1); i--) {
            if (strcmp(getChannelName((float) i / 10), "No signal") != 0) {
                return (float) i / 10;
            }
        }

    }
    return 0;
}

char* getChannelName(float channel)
{
    int channelInt = (int) round(channel * 10);
    switch (channelInt) {
        case INFO_FM: return "Info FM";
        case MUSIC_FM: return "Music FM";
        case JAZZY_FM: return "Jazzy FM";
        case CLASSIC_FM: return "Classic FM";
        case CLUB_FM: return "Club FM";
        default: return "No signal";
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

    volumeUp.Mode = GPIO_MODE_IT_RISING_FALLING;
    volumeDown.Mode = GPIO_MODE_IT_RISING_FALLING;
    channelUp.Mode = GPIO_MODE_IT_RISING_FALLING;
    channelDown.Mode = GPIO_MODE_IT_RISING_FALLING;

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
