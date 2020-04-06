#include "debounce.h"

struct StatusBounce button;

void InitStructDef()
{
	button.up = false;
	button.down = false;
	
	button.a = 0;
	button.b = 0;
	
	button.status_now = 0;
	button.status_after = 0;
	button.count = false;
}
