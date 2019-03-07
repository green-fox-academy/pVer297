#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {

	GPIO_InitTypeDef LED;
	GPIO_InitTypeDef BUTTON;

	HAL_Init();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	BUTTON.Pin = GPIO_PIN_4;
	BUTTON.Mode = GPIO_MODE_INPUT;
	BUTTON.Pull = GPIO_NOPULL;
	BUTTON.Speed = GPIO_SPEED_HIGH;

	LED.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_8 | GPIO_PIN_7;
	LED.Mode = GPIO_MODE_OUTPUT_PP;
	LED.Pull = GPIO_NOPULL;
	LED.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOB, &BUTTON);
	HAL_GPIO_Init(GPIOF, &LED);
	int counter = 0;
	int isPressed = 0;
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

		if(HAL_GPIO_ReadPin(GPIOB, BUTTON.Pin) && !isPressed){
			counter++;
			isPressed = 1;
		} else if (!HAL_GPIO_ReadPin(GPIOB, BUTTON.Pin) && isPressed){
			isPressed = 0;
		}

		if (counter > 15) {
			counter = 0;
		}
	}
}
