#ifndef Calculator_INC_GRD
#define Calculator_INC_GRD
#include "keyboard.hpp"
extern "C" void Calculator(void);
//"CalculatorInit()" only runs once, Calculator runs in the loop
extern "C" void CalculatorInit(void);
extern Keyboard kb;
#endif
