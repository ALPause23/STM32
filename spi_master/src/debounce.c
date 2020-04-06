#include "debounce.h"

struct StatusBounce button;

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

void EventForButton()
{
		if(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == SET)
		{
			SPI_I2S_SendData(SPI1, 0x0A);
			while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY));
		}
}
