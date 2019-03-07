#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

UART_HandleTypeDef UartHandle;

int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);

    /* enable the clock of the used peripherial instance */
    __HAL_RCC_USART1_CLK_ENABLE();

    /* defining the UART configuration structure */
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &UartHandle);

    char hello[] = "Hello World!\r\n";

    while (1) {

        HAL_Delay(1000);
        BSP_LED_Toggle(LED1);
        HAL_UART_Transmit(&UartHandle, (uint8_t*) hello, strlen(hello), 0xFFFF);
    }
}
