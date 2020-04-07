#include "button.h"
#include "global.h"

struct StatusBounce button;
GPIO_InitTypeDef gpioINT;

void InitStructDef()
{
	button.up = false;
	button.down = false;
	
	button.a = 0;
	button.b = 0;
	
	button.status_now = 0;
	button.status_after = 0;
	button.count = false;
}

int EventForButton()
{
		if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == SET)
		{
			SPI_I2S_SendData(SPI1, 0x0A);
			while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY));
		}
		//flags.ButtonIRQ = false;
		return 0;
}

void InitButtonUSER()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
		
	gpioINT.GPIO_Mode = GPIO_Mode_IN;
	gpioINT.GPIO_Pin = GPIO_Pin_0;
	gpioINT.GPIO_Speed = GPIO_Speed_50MHz;
	gpioINT.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &gpioINT);
	
	
}
