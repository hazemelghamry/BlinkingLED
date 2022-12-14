#ifndef SysTick_Interface_H_
#define SysTick_Interface_H_

#include "STD_TYPES.h"

void SysTick_Init(void);
void Set_Time(u32 time);
void SysTick_Handler(void);
void SetCallBackFunction(void (*CallBack)(void));
#endif