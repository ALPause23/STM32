#include "global.h"

struct FlagsPrj FLAG = {
	FLAG_DISABLE,
	FLAG_DISABLE,
};

uint16_t time_count_ms = 0x00;
uint16_t data = 0x00;

void SetFlag(uint8_t mark)
{
	FLAG.tim2_count_LED = mark;
}
