#ifndef __BUTTON_H__
	#define __BUTTON_H__
	
	#include "stm32f4xx.h"
	#include "stdbool.h"
	#include "spi.h"

	#define UP    1
	#define DOWN  0

	struct StatusBounce
	{
		bool up; // нажатие
		bool down; // отпускание
		
		int a; //счётчик в нажатие
		int b; // счетчик в отпусание
		
		uint8_t status_now; // текущее состояние кнопки (в данный момент)
		uint8_t status_after; // прошлое состояние
		bool count; //идёт ли счёт
	};
	
	extern struct StatusBounce button;
	extern GPIO_InitTypeDef gpioINT;
	
	void InitStructDef();
	uint8_t EventForButton();
	void InitButtonUSER();

#endif