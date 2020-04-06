#include "spi.h"

SPI_InitTypeDef spi1;
GPIO_InitTypeDef gpioA;

void InitSPI1()
{
	InitGpioSpi();
	
	spi1.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi1.SPI_Mode = SPI_Mode_Master;
	spi1.SPI_DataSize = SPI_DataSize_8b;
	spi1.SPI_CPOL = SPI_CPOL_Low;
	spi1.SPI_CPHA = SPI_CPHA_1Edge;
	spi1.SPI_NSS = SPI_NSS_Soft;
	spi1.SPI_FirstBit = SPI_FirstBit_LSB;
	spi1.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	SPI_Init(SPI1, &spi1);
	
	SPI_Cmd(SPI1, ENABLE);
}

void InitGpioSpi()
{
	GPIO_StructInit(&gpioA);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); //SPI
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); //SCK

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	gpioA.GPIO_Mode = GPIO_Mode_AF;
  gpioA.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	gpioA.GPIO_Speed = GPIO_Speed_50MHz;
	gpioA.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &gpioA);
}
	