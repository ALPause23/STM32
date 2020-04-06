#include "gpio.h"

GPIO_InitTypeDef gpioC;

void InitGPIO(void)
{
	GPIO_StructInit(&gpioC);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 
		
				
  gpioC.GPIO_Mode = GPIO_Mode_IN;
  gpioC.GPIO_Pin = GPIO_Pin_7;
	gpioC.GPIO_OType = GPIO_OType_PP;
	gpioC.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpioC);
}
