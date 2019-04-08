#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"
#include <string.h>
#include <stdlib.h>

#define UART_INTERRUPT_PRIORITY 2
#define INPUT_CAPTURE_INTERRUPT_PRIORITY 4
#define BUFFER_SIZE 5
#define CLOCK_SPEED 108000000

#define P_CONTROL_CONST 0.1
#define PI_P_CONTROL_CONST 0.1
#define PI_I_CONTROL_CONST 0.05
#define CTRL_MIN 0
#define CTRL_MAX 100

typedef enum
{
    UART_P,
    UART_PI,
    POT_P,
    POT_PI
} Control_state;
#define NUM_OF_CONTROL_STATES 4

//UART
UART_HandleTypeDef uart_handle;
//ADC
GPIO_InitTypeDef adc_pin;
ADC_HandleTypeDef adc_handle;
//PWM TIMER
TIM_HandleTypeDef pwm;
GPIO_InitTypeDef pwm_pin;
//IC TIMER
TIM_HandleTypeDef ic_timer;
GPIO_InitTypeDef ic_pin;

char current_char;
char buffer[BUFFER_SIZE] = "";
volatile int ellapsed_counter = 0;
volatile uint32_t last_count = 0;
volatile uint32_t RPM = 0;
volatile int ref_rpm = 0;
Control_state control_state = UART_PI;

int integral = 0;

void init_uart();
void init_pwm();
void init_ic();
void init_adc();
void uart_print_int(UART_HandleTypeDef* handle, int to_print);
void uart_print_string(UART_HandleTypeDef* handle, const char* to_print);
double p_controller(int ref, int engine_read);
double pi_controller(int ref, int engine_read);
char* state_to_string(Control_state state);

double lerp(double numToMap, double numMinVal, double numMaxVal, double targetMinVal, double targetMaxVal)
{
    return ((((numToMap - numMinVal) * (targetMaxVal - targetMinVal)) / (numMaxVal - numMinVal)) + targetMinVal);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_adc();
    init_uart();
    HAL_UART_Receive_IT(&uart_handle, &current_char, 1);
    init_pwm();
    init_ic();
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
    int counter = 0;

    int pot_val = 0;
    while (1) {
        /*HAL_ADC_Start(&adc_handle);

        if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            pot_val = HAL_ADC_GetValue(&adc_handle);
            pot_val = (int) lerp(pot_val, 0, 4095, 0, 5200);
        }
        if (control_state == UART_P) {
            __HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, p_controller(ref_rpm, RPM));
        } else if (control_state == UART_PI) {
            __HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, pi_controller(ref_rpm, RPM));
        } else if (control_state == POT_P) {
            __HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, p_controller(pot_val, RPM));
        } else if (control_state == POT_PI) {
            __HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, pi_controller(pot_val, RPM));
        }*/

        __HAL_TIM_SET_COMPARE(&pwm, TIM_CHANNEL_1, pi_controller(ref_rpm, RPM));
        if (counter >= 10) {
            char string[50];
            sprintf(string, "%d %d %d\n", ref_rpm, RPM, __HAL_TIM_GET_COMPARE(&pwm, TIM_CHANNEL_1));
            HAL_UART_Transmit(&uart_handle, string, strlen(string), 0xFFFF);
            counter = 0;
        }
        RPM = 0;
        counter++;
        HAL_Delay(10);

    }
}

double p_controller(int ref, int engine_read)
{
    int error = ref - engine_read;
    double ctrler_out = P_CONTROL_CONST * error;

    if (ctrler_out < CTRL_MIN)
        ctrler_out = CTRL_MIN;
    if (ctrler_out > CTRL_MAX)
        ctrler_out = CTRL_MAX;

    return ctrler_out;
}

double pi_controller(int ref, int engine_read)
{
    if (ref == 0) {
        integral = 0;
        return 0;
    }
    int error = ref - engine_read;
    integral += error;

    double ctrler_out = PI_P_CONTROL_CONST * error + PI_I_CONTROL_CONST * integral;

    if (ctrler_out < CTRL_MIN) {
        ctrler_out = CTRL_MIN;
        integral -= error;
    } else if (ctrler_out > CTRL_MAX) {
        ctrler_out = CTRL_MAX;
        integral -= error;
    }
    return ctrler_out;
}

void init_uart()
{
    __HAL_RCC_USART1_CLK_ENABLE();

    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);

    HAL_NVIC_SetPriority(USART1_IRQn, UART_INTERRUPT_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
}

void init_pwm()
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    pwm_pin.Pin = GPIO_PIN_4;
    pwm_pin.Mode = GPIO_MODE_AF_PP;
    pwm_pin.Pull = GPIO_NOPULL;
    pwm_pin.Speed = GPIO_SPEED_HIGH;
    pwm_pin.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &pwm_pin);

    __HAL_RCC_TIM3_CLK_ENABLE();

    HAL_TIM_PWM_DeInit(&pwm);
    pwm.Instance = TIM3;
    pwm.Init.Prescaler = 2160 - 1;
    pwm.Init.Period = 100 - 1;
    pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&pwm);

    TIM_OC_InitTypeDef pwm_config;

    pwm_config.Pulse = 0;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&pwm, &pwm_config, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&pwm, TIM_CHANNEL_1);
}

void init_ic()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    ic_pin.Pin = GPIO_PIN_15;
    ic_pin.Mode = GPIO_MODE_AF_OD;
    ic_pin.Pull = GPIO_NOPULL;
    ic_pin.Speed = GPIO_SPEED_HIGH;
    ic_pin.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &ic_pin);

    __HAL_RCC_TIM2_CLK_ENABLE();

    ic_timer.Instance = TIM2;
    ic_timer.Init.Prescaler = 0;
    ic_timer.Init.Period = UINT16_MAX;
    ic_timer.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    ic_timer.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&ic_timer);

    HAL_TIM_IC_Init(&ic_timer);

    TIM_IC_InitTypeDef ic_config;

    ic_config.ICPrescaler = TIM_ICPSC_DIV1;
    ic_config.ICSelection = TIM_ICSELECTION_DIRECTTI;
    ic_config.ICPolarity = TIM_ICPOLARITY_RISING;
    ic_config.ICFilter = 0;

    HAL_TIM_IC_ConfigChannel(&ic_timer, &ic_config, TIM_CHANNEL_1);

    HAL_NVIC_SetPriority(TIM2_IRQn, INPUT_CAPTURE_INTERRUPT_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    HAL_TIM_Base_Start_IT(&ic_timer);
    HAL_TIM_IC_Start_IT(&ic_timer, TIM_CHANNEL_1);
}

void init_adc()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    adc_pin.Mode = GPIO_MODE_ANALOG;
    adc_pin.Pin = GPIO_PIN_0;
    adc_pin.Speed = GPIO_SPEED_FAST;
    adc_pin.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &adc_pin);

    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    HAL_ADC_Init(&adc_handle);

    ADC_ChannelConfTypeDef adc_channel_config;

    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_11) {
        control_state = (control_state + 1) % NUM_OF_CONTROL_STATES;
    }
}

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&ic_timer);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM2) {
        int steps = ellapsed_counter * UINT16_MAX + __HAL_TIM_GET_COUNTER(htim) - last_count;
        double period = (1.0 / CLOCK_SPEED) * steps;
        RPM = ((1.0 / period) * 60) / 7;

        last_count = __HAL_TIM_GET_COUNTER(htim);
        ellapsed_counter = 0;
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM2) {
        ellapsed_counter++;
    }
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if (huart->Instance == USART1) {
        if (current_char != '\n' && current_char != '\r' && (strlen(buffer) + 1) < BUFFER_SIZE) {
            strcat(buffer, &current_char);
        } else {
            if (strcmp(buffer, "") != 0) {
                int rpm_val = strtol(buffer, NULL, 10);
                if (rpm_val >= 0 && rpm_val <= 5200) {
                    ref_rpm = rpm_val;
                }
            }
            memset(buffer, '\0', BUFFER_SIZE);
        }
        HAL_UART_Receive_IT(&uart_handle, &current_char, 1);
    }
}

void uart_print_int(UART_HandleTypeDef* handle, int to_print)
{
    char string[10];
    sprintf(string, "%d\n", to_print);
    HAL_UART_Transmit(handle, string, strlen(string), 0xFFFF);
}

void uart_print_string(UART_HandleTypeDef* handle, const char* to_print)
{
    char string[strlen(to_print) + 2];
    strcpy(string, to_print);
    strcat(string, "\n\0");
    HAL_UART_Transmit(handle, string, strlen(string), 0xFFFF);
}

char* state_to_string(Control_state state)
{
    switch (state) {
        case UART_P:
            return "UART control. P controller";
        case UART_PI:
            return "UART control. PI controller";
        case POT_P:
            return "Pot control. P controller";
        case POT_PI:
            return "Pot control. PI controller";
        default:
            return "???";
    }
}