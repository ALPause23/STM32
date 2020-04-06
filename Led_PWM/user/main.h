#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"
#include "ports.h"

void port_ini(void);
void delay(int n);

void port_ini(void)
{
	GPIO_InitTypeDef InitA0; //для кнопки
	GPIO_InitTypeDef InitD; //для светодиодов
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//включим тактирование порта D
	
	//светодиоды
	InitD.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|
		GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	InitD.GPIO_Mode = GPIO_Mode_OUT;
	InitD.GPIO_OType = GPIO_OType_PP;
	InitD.GPIO_Speed = GPIO_Speed_2MHz;
	InitD.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD,&InitD); //инициализация ножек порта

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//включим тактирование порта A

	//кнопка
	InitA0.GPIO_Pin = GPIO_Pin_0;
	InitA0.GPIO_Mode = GPIO_Mode_IN;
	InitA0.GPIO_OType = GPIO_OType_OD;
	InitA0.GPIO_Speed = GPIO_Speed_2MHz;
	InitA0.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&InitA0); //инициализация ножек порта
}

void delay(int n)
{
	while(n>0) n--;
}

#endif /* MAIN_H_ */
