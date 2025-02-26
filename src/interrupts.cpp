// this file contains definitions for the callback functions used by the HAL for
// interrupts
#include "Calculator.hpp"
extern "C" {
#include "main.h"
#include "stm32f7xx.h"
/*
 * Example:
 *
 * void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
 * keyHasBeenPressed = true;
 * }
 *
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM6) {
        kb.readAllKeys();
    }
}
}
