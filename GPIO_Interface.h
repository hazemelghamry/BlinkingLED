#ifndef GPIO_Interface_H_
#define GPIO_Interface_H_

#include "STD_TYPES.h"
#include "GPIO_Private.h"
void Pin_Init(u8 PORT,u8 PIN,u8 *Config);
void DIO_WriteChannel(u8 Port,u32 PIN,u32 Level);
u8 DIO_ReadChannel(u8 Port,u8 PIN);
#endif