#include "calculator.hpp"
#include "main.h"
void calculator(void) {
    while (1) {
        HAL_GPIO_TogglePin(KEY_DIV_GPIO_Port, KEY_DIV_Pin);
    }
}
