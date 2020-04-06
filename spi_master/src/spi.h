#ifndef __SPI_H__
	#define __SPI_H__

	#include "stm32f4xx_spi.h"

	extern SPI_InitTypeDef spi1;
	extern GPIO_InitTypeDef gpioA;
	void InitSPI1();
	void InitGpioSpi();

#endif