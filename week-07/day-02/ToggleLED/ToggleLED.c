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
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    BSP_LED_Init(LED1);
    int isOn = 0;

	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			isOn = 1 - isOn;
			HAL_Delay(250);
		}

		if(isOn){
			BSP_LED_On(LED1);
		} else {
			BSP_LED_Off(LED1);
		}
	}
}

