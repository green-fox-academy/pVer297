#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

uint32_t last_pressed = 0;
const int press_delay = 150;

GPIO_InitTypeDef LED;
GPIO_InitTypeDef EXT_BUTTON;
volatile int counter = 0;

void init_led()
{
    __HAL_RCC_GPIOF_CLK_ENABLE();

    LED.Pin = GPIO_PIN_10;
    LED.Pull = GPIO_NOPULL;
    LED.Speed = GPIO_SPEED_FAST;
    LED.Mode = GPIO_MODE_OUTPUT_PP;

    HAL_GPIO_Init(GPIOF, &LED);
}

void init_ext_button()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    EXT_BUTTON.Pin = GPIO_PIN_4;
    EXT_BUTTON.Pull = GPIO_NOPULL;
    EXT_BUTTON.Speed = GPIO_SPEED_FAST;
    EXT_BUTTON.Mode = GPIO_MODE_IT_RISING;

    HAL_GPIO_Init(GPIOB, &EXT_BUTTON);

    HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

int main(void)
{
    HAL_Init();
    init_led();
    init_ext_button();
    while (1) {
    }
}

void EXTI4_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint32_t current_time = HAL_GetTick();
    if (current_time < last_pressed + press_delay) {
        return;
    }

    last_pressed = current_time;
    if (GPIO_Pin == GPIO_PIN_4) {
        if (counter < 4) {
            counter++;
        } else {
            counter = 0;
            HAL_GPIO_TogglePin(GPIOF, LED.Pin);
        }
    }
}