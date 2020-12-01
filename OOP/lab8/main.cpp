#include "console.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "tests.h"

int main()
{
	
	TaskConsole console;
	console.run();
	_CrtDumpMemoryLeaks();
	/*Tests TestTasks;
	TestTasks.TestDomain();
	TestTasks.TestController();*/
	return 0;
}