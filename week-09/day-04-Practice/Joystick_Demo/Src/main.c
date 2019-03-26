#include <string.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

UART_HandleTypeDef UartHandle;

GPIO_InitTypeDef gpio_adc_pin;            /* GPIO config for PF10 pin */
ADC_HandleTypeDef x_adc_handle;            /* ADC handle */
ADC_HandleTypeDef y_adc_handle;            /* ADC handle */
ADC_ChannelConfTypeDef adc_channel_config;    /* ADC channel config for channel 8 */
DMA_HandleTypeDef hdma_adc3;            /* DMA handle */

#define ADC_SAMPLES 2000

uint16_t x_adc_array[ADC_SAMPLES];            /* array for ADC measurements */
uint16_t y_adc_array[ADC_SAMPLES];
/* signaling flag whether the DMA finished the 2000 measurements, and the adc_arary is full */
volatile int ready = 0;

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    __HAL_RCC_USART1_CLK_ENABLE();
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    BSP_COM_Init(COM1, &UartHandle);

    __HAL_RCC_GPIOF_CLK_ENABLE();
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_10;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOF, &gpio_adc_pin);

    __HAL_RCC_GPIOA_CLK_ENABLE();
    gpio_adc_pin.Pin = GPIO_PIN_0;
    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    __HAL_RCC_ADC3_CLK_ENABLE();
    x_adc_handle.Instance = ADC3;
    x_adc_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
    x_adc_handle.Init.NbrOfConversion = 2;
    x_adc_handle.Init.ContinuousConvMode = ENABLE;
    //adc_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    HAL_ADC_Init(&x_adc_handle);

    y_adc_handle.Instance = ADC3;
    y_adc_handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
    y_adc_handle.Init.NbrOfConversion = 2;
    y_adc_handle.Init.ContinuousConvMode = ENABLE;
    HAL_ADC_Init(&y_adc_handle);

    adc_channel_config.Channel = ADC_CHANNEL_8;
    adc_channel_config.Rank = 0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&x_adc_handle, &adc_channel_config);

    adc_channel_config.Channel = ADC_CHANNEL_8;
    adc_channel_config.Rank = 1;
    HAL_ADC_ConfigChannel(&y_adc_handle, &adc_channel_config);

    __HAL_RCC_DMA2_CLK_ENABLE();
    hdma_adc3.Instance = DMA2_Stream0;                  /* we need to look after in data-sheet, which DMA */
    hdma_adc3.Init.Channel = DMA_CHANNEL_2;             /* and which stream can be used with ADC3 */
    hdma_adc3.Init.Direction = DMA_PERIPH_TO_MEMORY;    /* ADC3 peripheral -> uint16_t adc_array[2000] */
    hdma_adc3.Init.PeriphInc = DMA_PINC_DISABLE;        /* ADC3 peripheral cannot be incremented */
    /* we don't need index variable to fill up the 2000-sized array, it is done automatically with MemInc: */
    hdma_adc3.Init.MemInc = DMA_MINC_ENABLE;
    hdma_adc3.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;   /* half-word = 2 byte (12 bit ADC!) */
    hdma_adc3.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;      /* same here*/
    hdma_adc3.Init.Mode = DMA_NORMAL;
    hdma_adc3.Init.Priority = DMA_PRIORITY_LOW;
    hdma_adc3.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    HAL_DMA_Init(&hdma_adc3);

    __HAL_LINKDMA(&x_adc_handle, DMA_Handle, hdma_adc3);  /* link together DMA2 and ADC3 */
    __HAL_LINKDMA(&y_adc_handle, DMA_Handle, hdma_adc3);

    /* using interrupt to set ready flag, to check whether the 2000 measurements are done */
    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

    HAL_ADC_Start_DMA(&x_adc_handle, (uint32_t*) x_adc_array, ADC_SAMPLES);    /* starting ADC in DMA mode */
    HAL_ADC_Start_DMA(&y_adc_handle, (uint32_t*) y_adc_array, ADC_SAMPLES);    /* starting ADC in DMA mode */

    char string[50];
    while (1) {
        HAL_Delay(250);

        /* check if the 2000 measurements are done, if yes we can process it */
        if (ready == 1) {
            /* stop DMA if 2000 measurement are made*/
            HAL_ADC_Stop_DMA(&x_adc_handle);

            /* avaraging */
            int sumX = 0;
            int sumY = 0;
            int i;
            for (i = 0; i < 2000; i++) {
                sumX += x_adc_array[i];
                sumY += y_adc_array[i];
            }
            sprintf(string, "X: %d Y: %d\n", sumX / ADC_SAMPLES, sumY / ADC_SAMPLES);
            HAL_UART_Transmit(&UartHandle, string, strlen(string), 0xFFFF);
            /* set flag back to 0 */
            ready = 0;

            /* restarting ADC in DMA mode */
            HAL_ADC_Start_DMA(&x_adc_handle, (uint32_t*) x_adc_array, ADC_SAMPLES);
        }
    }
}

void DMA2_Stream0_IRQHandler()
{
    HAL_DMA_IRQHandler(&hdma_adc3);
}

/* called, when 2000 measurements are done */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* adc_handle)
{
    /* signal the main program, that measurements are done */
    ready = 1;
}