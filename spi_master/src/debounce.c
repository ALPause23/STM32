#include "debounce.h"

void InitStructDef(struct StatusBounce x)
{
	x.up = false;
	x.down = false;
	
	x.a = 0;
	x.b = 0;
	
	x.status_now = 0;
	x.status_after = 0;
	x.count = false;
}
