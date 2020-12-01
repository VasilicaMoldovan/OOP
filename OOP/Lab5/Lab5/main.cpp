#include "console.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "tests.h"

int main()
{
	
	TaskRepository *baseRepository = new FileRepository();
	TaskRepository *fileRepository = new FileRepository();
	RepositoryValidator *repoValidator = new RepositoryValidator();
	TaskControllerModeA mainController(baseRepository, fileRepository, repoValidator);
	TaskConsole console(mainController);
	console.run();
	_CrtDumpMemoryLeaks();
	/*Tests TestTasks;
	TestTasks.TestControllerLab9();*/
	return 0;
}