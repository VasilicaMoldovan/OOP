#include "console.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	TaskConsole console;
	console.run();
	_CrtDumpMemoryLeaks();
	return 0;
}