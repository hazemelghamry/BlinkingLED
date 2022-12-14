#include "STD_TYPES.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "SysTick_Interface.h"
#include "SysTick_Private.h"
#include "BIT_MATH.h"
static u32 On_Time=5;
static u32 Off_Time=2;
static u8 f=1;
static u8 counter=1;
void Toggle(void);
int main(void)
{
PORT_Config ConfigA={{DIO,OUTPUT},{DIO,OUTPUT},{DIO,OUTPUT},{DIO,OUTPUT},{DIO,OUTPUT},{DIO,OUTPUT},{DIO,OUTPUT},{DIO,OUTPUT}};
Pin_Init(PORT_A,PIN_0,ConfigA.Pin0);
DIO_WriteChannel(PORT_A, PIN_0, HIGH);
Set_Time(On_Time);
SysTick_Init();
SetCallBackFunction(&Toggle);
	while(1)
	{

	}
	return 0;
}
void Toggle(void){
	if(f==0&&counter==Off_Time){
		DIO_WriteChannel(PORT_A, PIN_0, HIGH);
		Set_Time(On_Time);
		f=1;
		counter=1;
	}
	else if(f==1&&counter==On_Time){
		DIO_WriteChannel(PORT_A, PIN_0, LOW);
		Set_Time(Off_Time);
		f=0;
		counter=1;
	}
	else 
		counter++;

}