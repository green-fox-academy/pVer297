#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* necessary include files */
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void) {
	HAL_Init();
	SystemClock_Config();
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	/* initializing LCD */
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

	int screenWidth = BSP_LCD_GetXSize();
	int screenHeight = BSP_LCD_GetYSize();

	BSP_TS_Init(screenWidth, screenHeight);

	int xPos = 40;
	int yPos = 40;
	int radius = 20;

	float xSpeed = 3;
	float ySpeed = 3;

	int buttonDown = 0;

	int wallWidth = 15;

	uint32_t color = (uint32_t) 0xFF000000;

	uint8_t* testString = "Hello World!";

	TS_StateTypeDef* TouchPtr = NULL;

	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY) && !buttonDown) {
			buttonDown = 1;
			xSpeed *= 1.1;
			;
			ySpeed *= 1.1;
		} else if (!BSP_PB_GetState(BUTTON_KEY) && buttonDown) {
			buttonDown = 0;
		}

		if (xPos >= screenWidth - radius - wallWidth) {
			xPos = screenWidth - radius - wallWidth;
			xSpeed = -xSpeed;
			color = (rand() % 0x00FFFFFF) + (uint32_t) 0xFF000000;
		} else if (xPos <= radius + wallWidth) {
			xPos = radius + wallWidth;
			xSpeed = -xSpeed;
			color = (rand() % 0x00FFFFFF) + (uint32_t) 0xFF000000;
		}

		if (yPos >= screenHeight - radius - wallWidth) {
			yPos = screenHeight - radius - wallWidth;
			ySpeed = -ySpeed;
			color = (rand() % 0x00FFFFFF) + (uint32_t) 0xFF000000;
		} else if (yPos <= radius + wallWidth) {
			yPos = radius + wallWidth;
			ySpeed = -ySpeed;
			color = (rand() % 0x00FFFFFF) + (uint32_t) 0xFF000000;
		}

		BSP_LCD_Clear(LCD_COLOR_WHITE);

		BSP_LCD_SetTextColor(LCD_COLOR_RED);

		BSP_LCD_DisplayStringAt(0, screenHeight * 0.1, testString, CENTER_MODE);

		BSP_LCD_FillRect(0, 0, wallWidth, screenHeight);
		BSP_LCD_FillRect(0, 0, screenWidth, wallWidth);
		BSP_LCD_FillRect(screenWidth - wallWidth, 0, wallWidth, screenHeight);
		BSP_LCD_FillRect(0, screenHeight - wallWidth, screenWidth, wallWidth);
		/* drawing a red circle */
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_FillCircle(xPos, yPos, radius);
		HAL_Delay(20);

		BSP_TS_GetState(TouchPtr);

		xPos = *TouchPtr->touchX;
		yPos = *TouchPtr->touchY;
	}
}

static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {}
#endif
