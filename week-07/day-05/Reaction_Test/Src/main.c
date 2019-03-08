#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* necessary include files */
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

uint32_t screenWidth;
uint32_t screenHeight;
TS_StateTypeDef Touches;
int startScreenState = 0;
RNG_HandleTypeDef randomNumber;

void init();
void delay_w_interrupt(int wait);
void showStartScreen();
void updateGameState();
void startGame();
int getReaction();
void showResult(int result);

typedef enum
{
    START_SCREEN,
    GAME,
    END_SCREEN
} GameState;

GameState gameState;

int main(void)
{
    init();
    int result = 0;

    while (1) {
        if (gameState == START_SCREEN)
            showStartScreen();

        if (gameState == GAME)
            result = getReaction();

        if (gameState == END_SCREEN)
            showResult(result);

        delay_w_interrupt(1000);
    }
}

void showResult(int result)
{
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    char str[5];
    sprintf(str, "%d ms", result);
    BSP_LCD_DisplayStringAt(0, screenHeight / 2 - LCD_DEFAULT_FONT.Height, "Your reaction time:", CENTER_MODE);
    BSP_LCD_DisplayStringAt(0, screenHeight / 2 + LCD_DEFAULT_FONT.Height, str, CENTER_MODE);
}

int getReaction()
{
    BSP_LCD_Clear(LCD_COLOR_GREEN);
    uint32_t start = HAL_GetTick();
    while (1) {
        BSP_TS_GetState(&Touches);
        if (Touches.touchDetected > 0)
            break;
    }
    gameState = END_SCREEN;
    return HAL_GetTick() - start;
}

void startGame()
{
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    uint32_t rand = HAL_RNG_GetRandomNumber(&randomNumber) % 7 + 3;
    for (int i = rand; i > 0; i--) {
        char str[2];
        sprintf(str, "%d", i);
        BSP_LCD_DisplayStringAt(0, screenHeight / 2, str, CENTER_MODE);
        HAL_Delay(1000);
    }
    gameState = GAME;
}

void updateGameState()
{
    switch (gameState) {
        case START_SCREEN: startGame();
            break;
        case GAME: getReaction();
            break;
        case END_SCREEN: break;
    }
}

void showStartScreen()
{
    if (startScreenState) {
        BSP_LCD_Clear(LCD_COLOR_WHITE);
        BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    } else {
        BSP_LCD_Clear(LCD_COLOR_LIGHTGREEN);
        BSP_LCD_SetBackColor(LCD_COLOR_LIGHTGREEN);
    }
    BSP_LCD_DisplayStringAt(0, screenHeight / 2 - LCD_DEFAULT_FONT.Height, "Let's play!", CENTER_MODE);
    BSP_LCD_DisplayStringAt(0, screenHeight / 2 + LCD_DEFAULT_FONT.Height, "Press here to start!", CENTER_MODE);
    startScreenState = 1 - startScreenState;
}

void delay_w_interrupt(int wait)
{
    uint32_t start = HAL_GetTick();
    uint32_t end = start + wait;
    while (end > HAL_GetTick()) {
        BSP_TS_GetState(&Touches);
        if (Touches.touchEventId[0] == TOUCH_EVENT_PRESS_DOWN)
            updateGameState();
    }
}

void init()
{
    HAL_Init();
    SystemClock_Config();
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);

    randomNumber.Instance = RNG;
    __HAL_RCC_RNG_CLK_ENABLE();
    HAL_RNG_Init(&randomNumber);

    screenWidth = BSP_LCD_GetXSize();
    screenHeight = BSP_LCD_GetYSize();
    BSP_TS_Init(screenWidth, screenHeight);
}

static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line){}
#endif