#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

typedef struct
{
    uint16_t x;
    uint16_t y;
} point_t;

typedef struct
{
    int x_speed;
    int y_speed;
} speed_t;

typedef struct
{
    point_t pos;
    speed_t speed;
    uint8_t radius;
    uint32_t color;
} ball_t;

uint32_t screen_width;
uint32_t screen_height;

RNG_HandleTypeDef randomNumber;

ball_t Ball = {{20, 20}, {5, 5}, 10, LCD_COLOR_BLACK};

void init_lcd();
void init_rng();

void draw_divider();
void draw_ball(const ball_t* ball);

void limit_ball(ball_t* ball);
void move_ball(ball_t* ball);
void reset_ball(ball_t* ball);

int get_random_speed();

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_lcd();
    init_rng();

    reset_ball(&Ball);
    while (1) {
        BSP_LCD_Clear(LCD_COLOR_WHITE);
        draw_divider();
        move_ball(&Ball);
        draw_ball(&Ball);
        HAL_Delay(40);
    }
}

void init_lcd()
{
    BSP_LCD_Init();

    screen_width = BSP_LCD_GetXSize();
    screen_height = BSP_LCD_GetYSize();

    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}

void draw_divider()
{
    uint32_t div_color = LCD_COLOR_BLACK;
    uint16_t div_width = 6;
    uint16_t div_height = 30;
    for (uint16_t i = 1; i <= screen_height - div_height; i += div_height) {
        BSP_LCD_SetTextColor(div_color);
        BSP_LCD_FillRect((uint16_t) ((screen_width / 2) - (div_width / 2)), i, div_width, div_height);
        div_color ^= 0x00FFFFFF;
    }
}

void draw_ball(const ball_t* ball)
{
    BSP_LCD_SetTextColor(ball->color);
    BSP_LCD_FillCircle(ball->pos.x, ball->pos.y, ball->radius);
}

void move_ball(ball_t* ball)
{
    ball->pos.x += ball->speed.x_speed;
    ball->pos.y += ball->speed.y_speed;

    limit_ball(ball);
}

void limit_ball(ball_t* ball)
{
    if (ball->pos.y <= 0 + ball->radius) {
        ball->pos.y = ball->radius;
        ball->speed.y_speed = -ball->speed.y_speed;
    } else if (ball->pos.y >= screen_height - ball->radius) {
        ball->pos.y = (uint16_t) screen_height - ball->radius;
        ball->speed.y_speed = -ball->speed.y_speed;
    }

    if (ball->pos.x <= 0 + ball->radius) { //left side out, right player wins
        reset_ball(ball);
    } else if (ball->pos.x >= screen_width - ball->radius) { //right side out, left player wins
        reset_ball(ball);
    }
}

void reset_ball(ball_t* ball)
{
    ball->pos.x = (uint16_t) (screen_width / 2);
    ball->pos.y = (uint16_t) (screen_height / 2);

    ball->speed.x_speed = 5 * get_random_speed();
    ball->speed.y_speed = 5 * get_random_speed();
}

int get_random_speed()
{
    int random = (int) HAL_RNG_GetRandomNumber(&randomNumber) % 2;

    if (random == 0) {
        return -1;
    } else {
        return 1;
    }
}

void init_rng()
{
    randomNumber.Instance = RNG;
    __HAL_RCC_RNG_CLK_ENABLE();
    HAL_RNG_Init(&randomNumber);
}
