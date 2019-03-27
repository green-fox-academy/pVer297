#include <stdlib.h>
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

#define FRAMERATE 30

typedef struct
{
    uint32_t addr[2];
    uint32_t front;
} screen_t;

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

typedef struct
{
    point_t pos;
    int score;
    uint16_t width;
    uint16_t height;
    uint32_t color;
} paddle_t;

uint32_t screen_width;
uint32_t screen_height;
screen_t Screen;

volatile uint8_t refresh_flag = 1;
volatile uint8_t touch_flag = 0;

paddle_t left_paddle;
paddle_t right_paddle;

RNG_HandleTypeDef randomNumber;
TIM_HandleTypeDef timer;

long frames = 0;
long last_poll_time = 0;

void init_lcd();
void init_rng();
void init_timer();

void draw_divider();
void draw_ball(const ball_t* ball);
void draw_paddle(paddle_t* paddle);
void draw_scores();

void limit_ball(ball_t* ball);
void move_ball(ball_t* ball);
void reset_ball(ball_t* ball);

void switch_buffer(screen_t* screen);

int check_collision(const ball_t* ball, const paddle_t* paddle);

ball_t create_ball(uint16_t x_pos, uint16_t y_pos, int x_speed, int y_speed, uint8_t radius, uint32_t color);
paddle_t create_paddle(uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height, uint32_t color);

int get_random_speed();
int get_sign(int number)
{
    if (number >= 0)
        return 1;
    else
        return -1;
}

double lerp(double numToMap, double numMinVal, double numMaxVal, double targetMinVal, double targetMaxVal)
{
    return ((((numToMap - numMinVal) * (targetMaxVal - targetMinVal)) / (numMaxVal - numMinVal)) + targetMinVal);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_lcd();
    BSP_TS_Init(FT5336_MAX_WIDTH, FT5336_MAX_HEIGHT);
    BSP_TS_ITConfig();
    init_rng();
    init_timer();

    ball_t Ball = create_ball(screen_width / 2, screen_height / 2, 5, 5, 7, LCD_COLOR_BLACK);
    left_paddle = create_paddle(10, screen_height / 2 - 40, 7, 80, LCD_COLOR_BLACK);
    right_paddle = create_paddle(screen_width - 10 - 7, screen_height / 2 - 40, 7, 80, LCD_COLOR_BLACK);

    reset_ball(&Ball);
    while (1) {
        if (touch_flag) {
            TS_StateTypeDef Touch;
            BSP_TS_GetState(&Touch);
            for (int i = 0; i < Touch.touchDetected; i++) {
                if (Touch.touchX[i] > (FT5336_MAX_WIDTH * 0.75)
                    && Touch.touchY[i] > right_paddle.height / 2
                    && Touch.touchY[i] < screen_height - right_paddle.height / 2) {

                    right_paddle.pos.y = Touch.touchY[i] - (uint16_t) (right_paddle.height / 2);

                } else if (Touch.touchX[i] < (FT5336_MAX_WIDTH * 0.25)
                    && Touch.touchY[i] > left_paddle.height / 2
                    && Touch.touchY[i] < screen_height - left_paddle.height / 2) {

                    left_paddle.pos.y = Touch.touchY[i] - (uint16_t) (left_paddle.height / 2);
                }
            }
            touch_flag = 0;
        }
        if (refresh_flag) {
            switch_buffer(&Screen);
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            draw_scores();
            draw_divider();
            move_ball(&Ball);

            if (Ball.speed.x_speed > 0) {
                if (check_collision(&Ball, &right_paddle)) {
                    Ball.speed.x_speed = -Ball.speed.x_speed;
                    int hit_multiplier = (int) lerp(Ball.pos.y - right_paddle.pos.y, 0, right_paddle.height, -5, 5);
                    Ball.speed.y_speed = abs(hit_multiplier) * get_sign(Ball.speed.y_speed);
                }
            } else {
                if (check_collision(&Ball, &left_paddle)) {
                    Ball.speed.x_speed = -Ball.speed.x_speed;
                    int hit_multiplier = (int) lerp(Ball.pos.y - left_paddle.pos.y, 0, left_paddle.height, -5, 5);
                    Ball.speed.y_speed = abs(hit_multiplier) * get_sign(Ball.speed.y_speed);
                }
            }

            draw_ball(&Ball);

            draw_paddle(&left_paddle);
            draw_paddle(&right_paddle);
            refresh_flag = 0;
            frames++;
            if (frames > 1000) {
                frames = 0;
                last_poll_time = HAL_GetTick();
            }
        }
    }
}

void switch_buffer(screen_t* screen)
{
    while (!(LTDC->CDSR & LTDC_CDSR_VSYNCS));
    BSP_LCD_SetLayerVisible(screen->front, DISABLE);
    screen->front ^= 1;
    BSP_LCD_SetLayerVisible(screen->front, ENABLE);
    BSP_LCD_SelectLayer(1 - screen->front);
}

void draw_scores()
{
    char left[20];
    sprintf(left, "Left: %d", left_paddle.score);

    char right[20];
    sprintf(right, "Right: %d", right_paddle.score);

    char fps[10];
    sprintf(fps, "FPS: %.3f", (float) frames / ((float) (HAL_GetTick() - last_poll_time) / 1000));

    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_DisplayStringAt(5, 5, left, LEFT_MODE);
    BSP_LCD_DisplayStringAt(5, 5, right, RIGHT_MODE);
    BSP_LCD_SetFont(&Font16);
    BSP_LCD_DisplayStringAt(0, screen_height - Font16.Height, fps, LEFT_MODE);
}

void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(TS_INT_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == TS_INT_PIN && !refresh_flag) {
        touch_flag = 1;
    }
}

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&timer);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM2) {
        refresh_flag = 1;
    }
}

void init_lcd()
{
    BSP_LCD_Init();
    screen_width = BSP_LCD_GetXSize();
    screen_height = BSP_LCD_GetYSize();
    Screen.addr[0] = LCD_FB_START_ADDRESS;
    Screen.addr[1] = LCD_FB_START_ADDRESS + (screen_width * screen_height * 4);
    Screen.front = 1;
    BSP_LCD_LayerDefaultInit(0, Screen.addr[0]);
    BSP_LCD_LayerDefaultInit(1, Screen.addr[1]);
    BSP_LCD_SetLayerVisible(0, DISABLE);
    BSP_LCD_SetLayerVisible(1, ENABLE);
    BSP_LCD_SelectLayer(0);
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
        right_paddle.score++;
        reset_ball(ball);
    } else if (ball->pos.x >= screen_width - ball->radius) { //right side out, left player wins
        left_paddle.score++;
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

ball_t create_ball(uint16_t x_pos, uint16_t y_pos, int x_speed, int y_speed, uint8_t radius, uint32_t color)
{
    ball_t ball;
    ball.pos.x = x_pos;
    ball.pos.y = y_pos;
    ball.speed.x_speed = x_speed;
    ball.speed.y_speed = y_speed;
    ball.radius = radius;
    ball.color = color;

    return ball;
}

paddle_t create_paddle(uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height, uint32_t color)
{
    paddle_t paddle;
    paddle.pos.x = x_pos;
    paddle.pos.y = y_pos;
    paddle.score = 0;
    paddle.width = width;
    paddle.height = height;
    paddle.color = color;

    return paddle;
}

void draw_paddle(paddle_t* paddle)
{
    BSP_LCD_SetTextColor(paddle->color);
    BSP_LCD_FillRect(paddle->pos.x, paddle->pos.y, paddle->width, paddle->height);
}

int check_collision(const ball_t* ball, const paddle_t* paddle)
{
    float ball_x = abs(ball->pos.x - paddle->pos.x - (paddle->width / 2));
    float x_dist = ((float) paddle->width / 2) + ball->radius;

    if (ball_x > x_dist)
        return 0;

    float ball_y = abs(ball->pos.y - paddle->pos.y - (paddle->height / 2));
    float y_dist = ((float) paddle->height / 2) + ball->radius;
    if (ball_y > y_dist)
        return 0;
    if (ball_x <= ((float) paddle->width / 2) || ball_y <= ((float) paddle->height / 2))
        return 1;

    float xCornerDist = ball_x - ((float) paddle->width / 2);
    float yCornerDist = ball_y - ((float) paddle->height / 2);
    float xCornerDistSq = xCornerDist * xCornerDist;
    float yCornerDistSq = yCornerDist * yCornerDist;
    float maxCornerDistSq = ball->radius * ball->radius;
    return (xCornerDistSq + yCornerDistSq) <= maxCornerDistSq;
}

void init_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE();
    timer.Instance = TIM2;
    timer.Init.Prescaler = 1080 - 1; //54000 -> 0.5ms | 10800 -> 0.1ms
    timer.Init.Period = (uint32_t) ((1000.0 / FRAMERATE) * 100) - 1; //12000 * 0.5ms = 6s | 2000 = 1s
    timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer);

    HAL_NVIC_SetPriority(TIM2_IRQn, 4, 0);

    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    HAL_TIM_Base_Start_IT(&timer);
}