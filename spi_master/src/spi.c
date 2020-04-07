#include "spi.h"
//#include "main.h"

// Master SPI1
SPI_InitTypeDef spi1;
GPIO_InitTypeDef gpioA;

// Slave SPI2
SPI_InitTypeDef spi2;
GPIO_InitTypeDef gpioB;

uint16_t data = 0;

// Init Master SPI
void InitSPI1()
{
	InitGpioSpi1();
	
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

// Init Slave SPI 
void InitSPI2()
{
	InitGpioSpi2();
	
	spi2.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi2.SPI_Mode = SPI_Mode_Slave;
	spi2.SPI_DataSize = SPI_DataSize_8b;
	spi2.SPI_CPOL = SPI_CPOL_Low;
	spi2.SPI_CPHA = SPI_CPHA_1Edge;
	spi2.SPI_NSS = SPI_NSS_Soft;
	spi2.SPI_FirstBit = SPI_FirstBit_LSB;
	spi2.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	SPI_Init(SPI2, &spi2);
	
	SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, ENABLE);
	NVIC_EnableIRQ(SPI2_IRQn);
	
	SPI_Cmd(SPI2, ENABLE);
}

void InitGpioSpi1()
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

void InitGpioSpi2()
{
	GPIO_StructInit(&gpioB);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE); //SPI
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //SCK

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2);
	gpioB.GPIO_Mode = GPIO_Mode_AF;
  gpioB.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	gpioB.GPIO_Speed = GPIO_Speed_50MHz;
	gpioB.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOB, &gpioB);
}

void SPI2_IRQHandler()
{
	if(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == RESET & SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == SET)
		{
			SPI_NSSInternalSoftwareConfig(SPI2, SPI_NSSInternalSoft_Set);
			for(int i = 0; i < 100; i++);
			SPI_NSSInternalSoftwareConfig(SPI2, SPI_NSSInternalSoft_Reset);
			data = SPI_I2S_ReceiveData(SPI2);	
		}
}
