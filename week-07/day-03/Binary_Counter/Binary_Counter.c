#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {

	GPIO_InitTypeDef LED;

	HAL_Init();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	LED.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_8 | GPIO_PIN_7;
	LED.Mode = GPIO_MODE_OUTPUT_PP;
	LED.Pull = GPIO_NOPULL;
	LED.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LED);
	int counter = 0;
	//HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	while (1) {
		if ((counter >> 0) & 1) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		}

		if ((counter >> 1) & 1) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		}

		if ((counter >> 2) & 1) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		if ((counter >> 3) & 1) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
		}

		HAL_Delay(1000);
		counter++;

		if (counter > 15) {
			counter = 0;
		}
	}
}
