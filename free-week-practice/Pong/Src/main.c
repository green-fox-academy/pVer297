#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

uint32_t screen_width;
uint32_t screen_height;

void init_lcd();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_lcd();



    BSP_LCD_SetTextColor(LCD_COLOR_RED);
    BSP_LCD_FillCircle(50, 50, 30);
    while (1) {
    }
}

void init_lcd(){
    BSP_LCD_Init();

    screen_width = BSP_LCD_GetXSize();
    screen_height = BSP_LCD_GetYSize();

    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}