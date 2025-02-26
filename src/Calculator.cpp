#include "Calculator.hpp"
#include "keyboard.hpp"
#include <main.h>
#include <stm32f7xx.h>
Keyboard kb;
void CalculatorInit(void) {
    // htim6 - defined in main.c
    extern TIM_HandleTypeDef htim6;
    HAL_TIM_Base_Start_IT(&htim6);
}
void Calculator(void) {
    char i = kb.read();
    if (i == kb.keyCodes.F1) {
        HAL_GPIO_WritePin(KEY_TEST_GPIO_Port, KEY_TEST_Pin, GPIO_PIN_SET);
        HAL_Delay(5);
        HAL_GPIO_WritePin(KEY_TEST_GPIO_Port, KEY_TEST_Pin, GPIO_PIN_RESET);
    }
}
