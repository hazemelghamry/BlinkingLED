#ifndef INT_Driver_Private_H_
#define INT_Driver_Private_H_ 

#include "STD_TYPES.h"

#define INTEN (0xE000E000+0x100)
#define INTDIS (0xE000E000+0x180)
#define INTPEND (0xE000E000+0x200)
#define INTUNPEND (0xE000E000+0x280)
#define INTPRI(n) *(volatile u32*)(0xE000E000+0x400+4*n)
#define SWTRIG *((volatile u32*)(0xE000E000+0xF00))
#define APINT  *((volatile u32*)(0xE000E000+0xD0C))
#define xxx 0
#define xxy 1
#define xyy 2
#define yyy 3
#endif