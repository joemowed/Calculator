#include "Calculator.hpp"
#include <main.h>
#include <stm32f7xx.h>
void CalculatorInit(void) {
    // htim6 - defined in main.c
    extern TIM_HandleTypeDef htim6;
    // HAL_TIM_Base_Start_IT(&htim6);
}
void Calculator(void) { HAL_GPIO_TogglePin(KEY_F1_GPIO_Port, KEY_F1_Pin); }
