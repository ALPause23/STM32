#include "gpio.h"

GPIO_InitTypeDef gpioC_led;

void InitGPIO(void)
{
	GPIO_StructInit(&gpioC_led);

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 
	
	gpioC_led.GPIO_Mode = GPIO_Mode_OUT;  // LED4 and LED3
	gpioC_led.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_8;
	gpioC_led.GPIO_OType = GPIO_OType_PP;
	gpioC_led.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpioC_led);
}
