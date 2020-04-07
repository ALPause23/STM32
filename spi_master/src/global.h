#ifndef __GLOBAL_H__
	#define __GLOBAL_H__

	#include "stm32f4xx.h"
	#include "stdbool.h"
	
	extern uint16_t data;
	extern struct FlagsPrj
	{
		bool ButtonIRQ;
	}FLAG;
	
#endif
