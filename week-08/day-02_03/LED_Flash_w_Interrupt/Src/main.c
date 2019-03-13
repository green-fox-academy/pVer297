#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

TIM_HandleTypeDef timer;

GPIO_InitTypeDef LED;

void init_timer();
void init_ext_led();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_ext_led();
    init_timer();
    while (1) {
    }
}

void init_timer()
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

void init_ext_led()
{
    __HAL_RCC_GPIOF_CLK_ENABLE();

    LED.Pin = GPIO_PIN_10;
    LED.Mode = GPIO_MODE_OUTPUT_PP;
    LED.Pull = GPIO_NOPULL;
    LED.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOF, &LED);
}

void TIM2_IRQHandler()
{
    /* saving the current frame and executing the interrupt callback */
    HAL_TIM_IRQHandler(&timer);
}

/* interrupt callback*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    /* checking if the catched timer is the one we want to work with */
    if (htim->Instance == TIM2) {
        HAL_GPIO_TogglePin(GPIOF, LED.Pin);
    }
}