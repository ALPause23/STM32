#include "misc.h"
#include "stdbool.h"
#include "debounce.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

#define HSE_VALUE    ((uint32_t)8000000)

struct StatusBounce button;
uint16_t data = 0;
void InitButtonUSER()
{
	GPIO_InitTypeDef gpioINT;

	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	
	gpioINT.GPIO_Mode = GPIO_Mode_IN;
	gpioINT.GPIO_Pin = GPIO_Pin_0;
	gpioINT.GPIO_Speed = GPIO_Speed_50MHz;
	gpioINT.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &gpioINT);
}


int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	InitSPI2();
	InitTim3();
	
	InitTim2();
	
	InitButtonUSER();
	
	InitStructDef(button);
	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Reset);
	while(1)
	{
				
//		if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == RESET & SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == SET)
//		{
//			SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
//			for(int i = 0; i < 100; i++);
//			SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Reset);
//			data = SPI_I2S_ReceiveData(SPI1);	
//		}
	}
}

//void InitEXTI()
//{
//	EXTI_InitTypeDef INT;
//	NVIC_InitTypeDef nvic;

//	
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
