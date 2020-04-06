#include "gpio.h"


GPIO_InitTypeDef gpioC;
GPIO_InitTypeDef gpioC_led;

void InitGPIO(void)
{
	GPIO_StructInit(&gpioC);
	GPIO_StructInit(&gpioC_led);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); // LED4 blue
		
	// Set AlternFunc in PA4-PA7
			
  gpioC.GPIO_Mode = GPIO_Mode_AF;
  gpioC.GPIO_Pin = GPIO_Pin_8;
	gpioC.GPIO_OType = GPIO_OType_PP;
	gpioC.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpioC);
	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);
	
	gpioC_led.GPIO_Mode = GPIO_Mode_OUT;
	gpioC_led.GPIO_Pin = GPIO_Pin_9;
	gpioC_led.GPIO_OType = GPIO_OType_PP;
	gpioC_led.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpioC_led);
}
