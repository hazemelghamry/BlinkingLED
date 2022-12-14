#include "STD_TYPES.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"

void Pin_Init(u8 PORT,u8 PIN,u8* Config){
	switch(PORT){
		case PORT_A:
		*((volatile u32*)(PORTA+GPIODEN))|=1<<PIN;
		*((volatile u32*)(System_Control_Base+RCGCGPIO))|=1;
			if (*Config==DIO)
			*((volatile u32*)(PORTA+GPIOAFSEL))&=(~(1<<PIN));
			else if (*Config==Alternating)
		*((volatile u32*)(PORTA+GPIOAFSEL))|=1<<PIN;
			if (*(Config+1)==INPUT)
					*((volatile u32*)(PORTA+GPIODIR))&=(~(1<<PIN));
			else if( *(Config+1)==OUTPUT)
					*((volatile u32*)(PORTA+GPIODIR))|=1<<PIN;
		break;
		case PORT_B:
				*((volatile u32*)(PORTB+GPIODEN))|=1<<PIN;
		*((volatile u32*)(System_Control_Base+RCGCGPIO))|=1<<1;
			if (*Config==DIO)
			*((volatile u32*)(PORTB+GPIOAFSEL))&=(~(1<<PIN));
			else if (*Config==Alternating)
		*((volatile u32*)(PORTB+GPIOAFSEL))|=1<<PIN;
			if (*(Config+1)==INPUT)
					*((volatile u32*)(PORTB+GPIODIR))&=(~(1<<PIN));
			else if( *(Config+1)==OUTPUT)
					*((volatile u32*)(PORTB+GPIODIR))|=1<<PIN;
		break;
		case PORT_C:
				*((volatile u32*)(PORTC+GPIODEN))|=1<<PIN;
		*((volatile u32*)(System_Control_Base+RCGCGPIO))|=1<<2;
			if (*Config==DIO)
			*((volatile u32*)(PORTC+GPIOAFSEL))&=(~(1<<PIN));
			else if (*Config==Alternating)
		*((volatile u32*)(PORTC+GPIOAFSEL))|=1<<PIN;
			if (*(Config+1)==INPUT)
					*((volatile u32*)(PORTC+GPIODIR))&=(~(1<<PIN));
			else if( *(Config+1)==OUTPUT)
					*((volatile u32*)(PORTC+GPIODIR))|=1<<PIN;
		break;
		case PORT_D:
		*((volatile u32*)(PORTD+GPIODEN))|=1<<PIN;
		*((volatile u32*)(System_Control_Base+RCGCGPIO))|=1<<3;
			if (*Config==DIO)
			*((volatile u32*)(PORTD+GPIOAFSEL))&=(~(1<<PIN));
			else if (*Config==Alternating)
		*((volatile u32*)(PORTD+GPIOAFSEL))|=1<<PIN;
			if (*(Config+1)==INPUT)
					*((volatile u32*)(PORTD+GPIODIR))&=(~(1<<PIN));
			else if( *(Config+1)==OUTPUT)
					*((volatile u32*)(PORTD+GPIODIR))|=1<<PIN;
		break;
		case PORT_E:
			*((volatile u32*)(PORTE+GPIODEN))|=1<<PIN;
		*((volatile u32*)(System_Control_Base+RCGCGPIO))|=1<<4;
			if (*Config==DIO)
			*((volatile u32*)(PORTE+GPIOAFSEL))&=(~(1<<PIN));
			else if (*Config==Alternating)
		*((volatile u32*)(PORTE+GPIOAFSEL))|=1<<PIN;
			if (*(Config+1)==INPUT)
					*((volatile u32*)(PORTE+GPIODIR))&=(~(1<<PIN));
			else if( *(Config+1)==OUTPUT)
					*((volatile u32*)(PORTE+GPIODIR))|=1<<PIN;
		break;
		case PORT_F:
			*((volatile u32*)(PORTF+GPIODEN))|=1<<PIN;
		*((volatile u32*)(System_Control_Base+RCGCGPIO))|=1<<5;
			if (*Config==DIO)
			*((volatile u32*)(PORTF+GPIOAFSEL))&=(~(1<<PIN));
			else if (*Config==Alternating)
		*((volatile u32*)(PORTF+GPIOAFSEL))|=1<<PIN;
			if (*(Config+1)==INPUT)
					*((volatile u32*)(PORTF+GPIODIR))&=(~(1<<PIN));
			else if( *(Config+1)==OUTPUT)
					*((volatile u32*)(PORTF+GPIODIR))|=1<<PIN;
		break;
	}

	
}
void DIO_WriteChannel(u8 Port,u32 PIN,u32 Level)
{
	u32 PINAdd=0xFF<<PIN;
	u32 LevelAdd;
	switch(Port)
	{
		case PORT_A:
			if(Level==HIGH){
				 LevelAdd=(Level<<PIN);
			*((volatile u32*)(PORTA+GPIODATA+(PINAdd<<2)))|=LevelAdd;
			}
			else{
				Level=0x1;
				 LevelAdd=(~Level)<<PIN;
				*((volatile u32*)(PORTA+GPIODATA+(PINAdd<<2)))&=LevelAdd;
			}
		break;
		case PORT_B:
			if(Level==HIGH){
				 LevelAdd=(Level<<PIN);
			*((volatile u32*)(PORTB+GPIODATA+(PINAdd<<2)))|=LevelAdd;
			}
			else{
				Level=0x1;
				 LevelAdd=(~Level)<<PIN;
				*((volatile u32*)(PORTB+GPIODATA+(PINAdd<<2)))&=LevelAdd;
			}
		break;
		case PORT_C:
			if(Level==HIGH){
				 LevelAdd=(Level<<PIN);
			*((volatile u32*)(PORTC+GPIODATA+(PINAdd<<2)))|=LevelAdd;
			}
			else{
				Level=0x1;
				 LevelAdd=(~Level)<<PIN;
				*((volatile u32*)(PORTC+GPIODATA+(PINAdd<<2)))&=LevelAdd;
			}
		break;
		case PORT_D:
		if(Level==HIGH){
				 LevelAdd=(Level<<PIN);
			*((volatile u32*)(PORTD+GPIODATA+(PINAdd<<2)))|=LevelAdd;
			}
			else{
				Level=0x1;
				 LevelAdd=(~Level)<<PIN;
				*((volatile u32*)(PORTD+GPIODATA+(PINAdd<<2)))&=LevelAdd;
			}
		break;
		case PORT_E:
			if(Level==HIGH){
				 LevelAdd=(Level<<PIN);
			*((volatile u32*)(PORTE+GPIODATA+(PINAdd<<2)))|=LevelAdd;
			}
			else{
				Level=0x1;
				 LevelAdd=(~Level)<<PIN;
				*((volatile u32*)(PORTE+GPIODATA+(PINAdd<<2)))&=LevelAdd;
			}
		break;
		case PORT_F:
		if(Level==HIGH){
				 LevelAdd=(Level<<PIN);
			*((volatile u32*)(PORTF+GPIODATA+(PINAdd<<2)))|=LevelAdd;
			}
			else{
				Level=0x1;
				 LevelAdd=(~Level)<<PIN;
				*((volatile u32*)(PORTF+GPIODATA+(PINAdd<<2)))&=LevelAdd;
			}
		break;
		
	}
	
}
u8 DIO_ReadChannel(u8 Port,u8 PIN){
	u32 PINAdd=1<<PIN;
	u8 data;
	switch(Port)
	{
		case PORT_A:
			data=*((volatile u32*)(PORTA+GPIODATA+(PINAdd<<2)))>>PIN;
		return data;
		case PORT_B:
			data=*((volatile u32*)(PORTB+GPIODATA+(PINAdd<<2)))>>PIN;
		return data;
		case PORT_C:
			data=*((volatile u32*)(PORTC+GPIODATA+(PINAdd<<2)))>>PIN;
		return data;
		case PORT_D:
			data=*((volatile u32*)(PORTD+GPIODATA+(PINAdd<<2)))>>PIN;
		return data;
		case PORT_E:
			data=*((volatile u32*)(PORTE+GPIODATA+(PINAdd<<2)))>>PIN;
		return data;
		case PORT_F:
			data=*((volatile u32*)(PORTF+GPIODATA+(PINAdd<<2)))>>PIN;
		return data;
	}
	
}