#ifndef __DEBOUNCE_H__
	#define __DEBOUNCE_H__
	
	#include "stm32f4xx.h"
	#include "stdbool.h"

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
	
	void InitStructDef();

#endif