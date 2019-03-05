/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {

	HAL_Init();
	BSP_LED_Init(LED1);
	int delay = 2000;
	int blinkCounter = 0;
	int speedUp = 1;

	while (1) {

		BSP_LED_On(LED1);
		HAL_Delay(delay);
		BSP_LED_Off(LED1);
		HAL_Delay(delay);
		blinkCounter++;
		if (blinkCounter == 3) {
			blinkCounter = 0;
			if (speedUp) {
				delay /= 2;
			} else {
				delay *= 2;
			}
		}
		if(delay < 250){
			delay = 500;
			speedUp = 0;
		} else if(delay > 2000){
			delay = 1000;
			speedUp = 1;
		}

	}
}

