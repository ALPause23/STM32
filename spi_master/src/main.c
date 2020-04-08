#include "misc.h"
#include "button.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "global.h"

#define HSE_VALUE    ((uint32_t)8000000)

int main(void)
{
	struct FlagsPrj *f_in_main;
	f_in_main = &FLAG;

	SystemInit();
	SystemCoreClockUpdate();
	
	InitGPIO();
	InitSPI1();
	InitSPI2();
	
	InitStructDef();
	InitButtonUSER();
	
//	InitTim3();
	InitTim2();
	
	while(1)
	{
		if(f_in_main->button_IRQ == FLAG_ENABLE)
			f_in_main->button_IRQ = EventForButton();
	}
}

//void InitEXTI()
//{
//	EXTI_InitTypeDef INT;
//	NVIC_InitTypeDef nvic;
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
//	
//	INT.EXTI_Line = EXTI_Line0;
//	INT.EXTI_Mode = EXTI_Mode_Event;
//	//INT.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//	INT.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&INT);
//	
//	nvic.NVIC_IRQChannel = EXTI0_IRQn;
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
//	nvic.NVIC_IRQChannelPreemptionPriority = 0;
//	nvic.NVIC_IRQChannelSubPriority = 0;
//	nvic.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&nvic);
//}
