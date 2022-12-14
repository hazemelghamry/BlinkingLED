#ifndef INT_Driver_Interface_H_
#define INT_Driver_Interface_H_

#include "STD_TYPES.h"
void INT_Enable(u8 INT_Number);
void INT_Disable(u8 INT_Number);
void INT_Pend(u8 INT_Number);
void INT_UnPend(u8 INT_Number);
void INT_SW_Trigger(u8 INT_Number);
void INT_Set_Priority(u8 INT_Number,u32 Priority);
void INT_Priority_Init(u8 Group);
#endif