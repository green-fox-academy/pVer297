#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {

	GPIO_InitTypeDef LED;

	HAL_Init();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	LED.Pin = GPIO_PIN_9 | GPIO_PIN_10;
	LED.Mode = GPIO_MODE_OUTPUT_PP;
	LED.Pull = GPIO_NOPULL;
	LED.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LED);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
	while (1) {
		HAL_GPIO_TogglePin(GPIOF, LED.Pin);
		HAL_Delay(500);
	}
}
