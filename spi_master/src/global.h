#ifndef __GLOBAL_H__
	#define __GLOBAL_H__
	
	#include "stm32f4xx.h"
	
	// Dedine state
	#define FLAG_ENABLE   							0x01
	#define FLAG_DISABLE  							0x00
	
	// Name for flags
	#define FLAG_BUTTON     							1
	#define FLAG_tim2_count_buttonUp      2
	#define FLAG_tim2_count_LED      			3
	
	typedef struct 
	{
		uint8_t button_IRQ; // flag click buttonUSER
		
		uint8_t tim2_count_buttonUp; // flag enable count time in TIM2 for click and up buttonUSER
		
		uint8_t tim2_count_LED; // flag enable count time in TIM2 for LED on to off
	}FlagsPrj;
	
		
	void SelectFlag(uint8_t fl, uint8_t mark);
	uint8_t GetFlag(uint8_t fl);
	
	void CountLedOn();
	void SetTimeCountMs(int a);
	
	void SetData(uint16_t d);
	uint16_t GetData();
	
#endif
