#include "global.h"

FlagsPrj FLAG = {FLAG_DISABLE, FLAG_DISABLE, FLAG_DISABLE};

uint16_t time_count_ms = 0x00;
uint16_t data = 0x00;  // global buffer SPI

void SetFlagButtonIRQ(uint8_t fl);
uint8_t GetFlagButtonIRQ();
void SetFlagTimCountButtonUP(uint8_t fl);
uint8_t GetFlagTimCountButtonUP();
void SetFlagTimCountLED(uint8_t fl);
uint8_t GetFlagTimCountLED();

/* This function set for selecteg flags in FlagsPrj FLAG*/
void SelectFlag(uint8_t fl, uint8_t mark)
{
	switch(fl)
	{
		case FLAG_BUTTON: {
			SetFlagButtonIRQ(mark);
			break;
		}
		case FLAG_tim2_count_buttonUp: {
			SetFlagTimCountButtonUP(mark);
			break;
		}
		case FLAG_tim2_count_LED: {
			SetFlagTimCountLED(mark);
			break;
		}
	}
}

/* This function return for selected flag in FlagsPrj FLAG*/
uint8_t GetFlag(uint8_t fl)
{
	switch(fl)
	{
		case FLAG_BUTTON: {
			return GetFlagButtonIRQ();
		}
		case FLAG_tim2_count_buttonUp: {
			return GetFlagTimCountButtonUP();
		}
		case FLAG_tim2_count_LED: {
			return GetFlagTimCountLED();
		}
	}
}

// Set/Get flag button_IRQ
void SetFlagButtonIRQ(uint8_t mark)
{
	FLAG.button_IRQ = mark;
}

uint8_t GetFlagButtonIRQ()
{
	return FLAG.button_IRQ;
}

// Set/Get flag tim2_count_buttonUp
void SetFlagTimCountButtonUP(uint8_t mark)
{
	FLAG.tim2_count_buttonUp = mark;
}

uint8_t GetFlagTimCountButtonUP()
{
	return FLAG.tim2_count_buttonUp;
}

// Set/Get flag tim2_count_LED
void SetFlagTimCountLED(uint8_t mark)
{
	FLAG.tim2_count_LED = mark;
}

uint8_t GetFlagTimCountLED()
{
	return FLAG.tim2_count_LED;
}


void CountLedOn()
{
	time_count_ms++;
}

void SetTimeCountMs(int a)
{
	time_count_ms = a;
}

void SetData(uint16_t d)
{
	data = d;
}

uint16_t GetData()
{
	return data;
}
