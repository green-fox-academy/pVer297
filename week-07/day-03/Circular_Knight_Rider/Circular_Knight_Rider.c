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

	uint16_t pinOn = GPIO_PIN_7;
	while (1) {
		HAL_GPIO_WritePin(GPIOF,LED.Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,pinOn,GPIO_PIN_SET);
		HAL_Delay(200);

		pinOn = pinOn << 1;

		if(pinOn > GPIO_PIN_10){
			pinOn = GPIO_PIN_7;
		}

	}
}
