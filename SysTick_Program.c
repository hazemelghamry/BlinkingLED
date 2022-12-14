#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SysTick_Config.h"
#include "SysTick_Interface.h"
#include "SysTick_Private.h"

void (*CallBackPtr)(void);
void SysTick_Init(void){
	STCURRENT=0;
	#if Clk==System_Clk
	SET_BIT(STCTRL,2);
	#else
	CLR_BIT(STCTRL,2);
	#endif
	#if INT==INT_OFF
	CLR_BIT(STCTRL,1);
	#else
	SET_BIT(STCTRL,1);
	#endif
	#if Enable==OFF
	CLR_BIT(STCTRL,0);
	#else
		SET_BIT(STCTRL,0);
	#endif
}
void Set_Time(u32 time)	
{
	STRELOAD=(time*16000000ul)-1;
}
void SetCallBackFunction(void (*CallBack)(void))
{
	CallBackPtr=CallBack;
}
void SysTick_Handler(void)
{
CallBackPtr();
	}


