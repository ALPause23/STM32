#ifndef __GLOBAL_H__
	#define __GLOBAL_H__
	
	#include "stm32f4xx.h"
	
	#define FLAG_ENABLE   0x01
	#define FLAG_DISABLE  0x00

	extern uint16_t data;
	extern uint16_t time_count_ms;
	extern struct FlagsPrj
	{
		uint8_t button_IRQ; // flag click buttonUSER
		
		uint8_t tim2_count_buttonUp; // flag enable count time int TIM3 for click and up buttonUSER
		
		uint8_t tim2_count_LED;
	}FLAG;
		
	void SetFlag(uint8_t mark);
#endif
