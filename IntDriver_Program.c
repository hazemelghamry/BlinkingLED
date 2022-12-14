#include "INT_Driver_Interface.h"
#include "INT_Driver_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void INT_Enable(u8 INT_Number)
{
		if(INT_Number<=31){
			SET_BIT(*((volatile u32*)INTEN),INT_Number);
		}
		else if(INT_Number<=63){
				SET_BIT(*((volatile u32*)(INTEN+0x04)),INT_Number);
		}
		else if(INT_Number<=95){
				SET_BIT(*((volatile u32*)(INTEN+0x08)),INT_Number);
		}
		else if(INT_Number<=127){
				SET_BIT(*((volatile u32*)(INTEN+0x0C)),INT_Number);
		}
		else if(INT_Number<=138){
				SET_BIT(*((volatile u32*)(INTEN+0x010)),INT_Number);
		}
}
void INT_Disable(u8 INT_Number){
	if(INT_Number<=31){
			SET_BIT(*((volatile u32*)INTDIS),INT_Number);
		}
		else if(INT_Number<=63){
				SET_BIT(*((volatile u32*)(INTDIS+0x04)),INT_Number);
		}
		else if(INT_Number<=95){
				SET_BIT(*((volatile u32*)(INTDIS+0x08)),INT_Number);
		}
		else if(INT_Number<=127){
				SET_BIT(*((volatile u32*)(INTDIS+0x0C)),INT_Number);
		}
		else if(INT_Number<=138){
				SET_BIT(*((volatile u32*)(INTDIS+0x010)),INT_Number);
		}
}

void INT_Pend(u8 INT_Number)
{
	if(INT_Number<=31){
			SET_BIT(*((volatile u32*)INTPEND),INT_Number);
		}
		else if(INT_Number<=63){
				SET_BIT(*((volatile u32*)(INTPEND+0x04)),INT_Number);
		}
		else if(INT_Number<=95){
				SET_BIT(*((volatile u32*)(INTPEND+0x08)),INT_Number);
		}
		else if(INT_Number<=127){
				SET_BIT(*((volatile u32*)(INTPEND+0x0C)),INT_Number);
		}
		else if(INT_Number<=138){
				SET_BIT(*((volatile u32*)(INTPEND+0x010)),INT_Number);
		}
}
void INT_UnPend(u8 INT_Number)
{
	if(INT_Number<=31){
			SET_BIT(*((volatile u32*)INTUNPEND),INT_Number);
		}
		else if(INT_Number<=63){
				SET_BIT(*((volatile u32*)(INTUNPEND+0x04)),INT_Number);
		}
		else if(INT_Number<=95){
				SET_BIT(*((volatile u32*)(INTUNPEND+0x08)),INT_Number);
		}
		else if(INT_Number<=127){
				SET_BIT(*((volatile u32*)(INTUNPEND+0x0C)),INT_Number);
		}
		else if(INT_Number<=138){
				SET_BIT(*((volatile u32*)(INTUNPEND+0x010)),INT_Number);
		}
}
void INT_Priority_Init(u8 Group)
{
	u32 temp=0;
	temp&=(0x05FA<<16);
	if(Group==xxx)
	{
		temp|=0x0<<8;
	}
	else if(Group==xxy){
		temp|=0x5<<8;
	}
	else if(Group==xyy){
		temp|=0x6<<8;
	}
	else if(Group==yyy){
		temp|=0x7<<8;
	}
	APINT=temp;
}
void INT_Set_Priority(u8 INT_Number,u32 Priority)
{
	u8 n= INT_Number/4;
	if(INT_Number==4*n){
		INTPRI(n)&=0xFFFFFF0F;
		INTPRI(n)|=Priority<<5;	
	}
	else if(INT_Number==4*n+1)
	{
			INTPRI(n)&=0xFFFF0FFF;
		INTPRI(n)|=Priority<<13;	
	}
	else if(INT_Number==4*n+2)
	{
			INTPRI(n)&=0xFF0FFFFF;
		INTPRI(n)|=Priority<<21;	
	}
	else if(INT_Number==4*n+3)
	{
			INTPRI(n)&=0x0FFFFFFF;
		INTPRI(n)|=Priority<<29;	
	}
}
void INT_SW_Trigger(u8 INT_Number){
	SET_BIT(SWTRIG,INT_Number);
}

