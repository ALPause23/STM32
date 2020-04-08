#include "button.h"
#include "global.h"

struct StatusBounce button;
GPIO_InitTypeDef gpioINT;

struct FlagsPrj *f_in_button = &FLAG;

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

uint8_t EventForButton()
{
	if(f_in_button->tim2_count_buttonUp == FLAG_DISABLE)
		f_in_button->tim2_count_buttonUp = FLAG_ENABLE;
	else
	{
		f_in_button->tim2_count_buttonUp = FLAG_DISABLE;
		SendSPI1(f_in_button->tim2_count_buttonUp);
		
	}
	return FLAG_DISABLE;
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
