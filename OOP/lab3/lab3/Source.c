#define _CRTDBG_MAP_ALLOC
#include "Console.h"
#include "Tests.h"
#include <crtdbg.h>

int main()
{
	runTests();
	run();
	_CrtDumpMemoryLeaks();

	return 0;
}