#ifndef __SPI_H__
	#define __SPI_H__

	#include "stm32f4xx_spi.h"
	
	extern SPI_InitTypeDef spi1;
	extern GPIO_InitTypeDef gpioA;
	extern SPI_InitTypeDef spi2;
	extern GPIO_InitTypeDef gpioB;	
	void InitSPI1();
	void InitSPI2();
	void InitGpioSpi1();
	void InitGpioSpi2();
	
#endif
