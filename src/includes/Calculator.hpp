#ifndef Calculator_INC_GRD
#define Calculator_INC_GRD
#ifdef __cplusplus
extern "C" void Calculator(void);
//"CalculatorInit()" only runs once, Calculator runs in the loop
extern "C" void CalculatorInit(void);
#else
void Calculator(void);
void CalculatorInit(void);
#endif
#endif
