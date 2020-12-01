#include "Evidence.h"
#include "EvidenceValidator.h"
#include "Exception.h"
#include "Repository.h"
#include "MemoryRepository.h"
#include "FileRepository.h"
#include "Controller.h"
#include "UI.h"
#include <iostream>

using namespace std;

void testAll()
{
	Evidence evidence{};
	evidence.tests();
	cout << "Tests done - EVIDENCE" << endl;

	EvidenceValidator validator{};
	validator.tests();
	cout << "Tests done - VALIDATOR" << endl;

	Repository *repository{};

	MemoryRepository memoryRepository{};
	memoryRepository.tests();
	cout << "Tests done - MEMORY REPO" << endl;

	FileRepository fileRepository{};
	fileRepository.tests();
	cout << "Tests done - FILE REPO" << endl;

	Controller controller{ &fileRepository,&memoryRepository,validator };
	controller.tests();
	cout << "Tests done - CONTROLLER" << endl;
}

int main()
{
	testAll();

	/*EvidenceValidator validator{};

	Repository *repository{};

	MemoryRepository memoryRepository{};

	FileRepository fileRepository{};

	Controller controller{ &fileRepository,&memoryRepository,validator };

	UI ui{ controller };

	ui.run();*/


	//system("pause");
	return 0;
}