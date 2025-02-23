// this file contains definitions for the callback functions used by the HAL for
// interrupts
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
    HAL_GPIO_TogglePin(KEY_TEST_GPIO_Port, KEY_TEST_Pin);
    HAL_GPIO_ReadPin(KEY_0_GPIO_Port, KEY_0_Pin);
    HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin);
}
}
