#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {

	GPIO_InitTypeDef LED;
	GPIO_InitTypeDef BUTTON;

	HAL_Init();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	LED.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_8 | GPIO_PIN_7;
	LED.Mode = GPIO_MODE_OUTPUT_PP;
	LED.Pull = GPIO_NOPULL;
	LED.Speed = GPIO_SPEED_HIGH;

	BUTTON.Pin = GPIO_PIN_4;
	BUTTON.Mode = GPIO_MODE_INPUT;
	BUTTON.Pull = GPIO_NOPULL;
	BUTTON.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &LED);
	HAL_GPIO_Init(GPIOB, &BUTTON);

	uint16_t pinOn = GPIO_PIN_7;
	int up = 1;
	int isPressed = 0;

	while (1) {
		HAL_GPIO_WritePin(GPIOF, LED.Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF, pinOn, GPIO_PIN_SET);
		HAL_Delay(75);
		if (up) {
			pinOn = pinOn << 1;
		} else {
			pinOn = pinOn >> 1;
		}
		if (pinOn >= GPIO_PIN_10 || pinOn <= GPIO_PIN_7) {
			up = 1 - up;
		}

		if (HAL_GPIO_ReadPin(GPIOB, BUTTON.Pin) && !isPressed) {
			up = 1 - up;
			isPressed = 1;
		} else if (!HAL_GPIO_ReadPin(GPIOB, BUTTON.Pin) && isPressed) {
			isPressed = 0;
		}
	}
}
