#ifndef __GPIO_H__ 
	#define __GPIO_H__
	
	#include "stm32f4xx_gpio.h"
	
	extern GPIO_InitTypeDef gpioC;
	extern GPIO_InitTypeDef gpioC_led;

	void InitGPIO(void);

#endif



