#include "Calculator.hpp"
#include "main.h"
void Calculator(void) {
    // user code goes here
    volatile int i = 8;
    volatile int j = sizeof(i);
    for (; j < i; j++) {
        i = 9;
        volatile int k = 8;
        volatile int z = 8;
        volatile int a = 8;
    }
}
