#ifndef GPIO_Private_H_
#define GPIO_Private_H_

#include "STD_TYPES.h"

#define OUTPUT 1
#define INPUT 0

#define DIO 1
#define Alternating 0
typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}DIO_ChannelType;

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
}DIO_PortType;

typedef struct{
	u8 Pin0[2];
	u8 Pin1[2];
	u8 Pin2[2];
	u8 Pin3[2];
	u8 Pin4[2];
	u8 Pin5[2];
	u8 Pin6[2];
	u8 Pin7[2];
}PORT_Config;

#define HIGH 1
#define LOW 0

#define PORTA 0x40004000
#define PORTB 0x40005000
#define PORTC 0x40006000
#define PORTD 0x40007000
#define PORTE 0x40024000
#define PORTF 0x40025000
#define GPIODATA 0x000
#define GPIODIR 0x400
#define RCGCGPIO 0x608
#define GPIOAFSEL 0x420
#define GPIODR2R 0x500
#define GPIODR4R 0x504
#define GPIODR8R 0x508
#define GPIOPUR  0x510
#define GPIOPDR  0x514
#define GPIODEN  0x51C
#define System_Control_Base 0x400FE000
#endif