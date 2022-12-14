#ifndef SysTick_Private_H_
#define SysTick_Private_H_

#define STCTRL *((volatile u32*)(0xE000E000 +0x010))
#define STRELOAD *((volatile u32*)(0xE000E000 +0x014))
#define STCURRENT *((volatile u32*)(0xE000E000 +0x018))

#define System_Clk 0
#define PIOSC 1

#define INT_OFF 0
#define INT_ON 1

#define OFF 0
#define ON 1

#endif