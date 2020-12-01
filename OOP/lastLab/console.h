#pragma once
#include "controller.h"

class TaskConsole {
private:
	TaskControllerModeA consoleVectorModeA;
	RefurbishmentValidator refurbishmentValidator;
	RepositoryValidator repoValidator;
public:
	TaskConsole(TaskControllerModeA consoleVectorModeA) { this->consoleVectorModeA = consoleVectorModeA; };
	void run();
	Refurbishment uiAddOrUpdateTask(char* token, std::string title, std::string date, std::string mirrorImage, std::string type, int numberOfRepetitions);
	void listAllRefurbishments(char listToBePrinted[]);
	void listAllRefurbishmentsWithProperty(std::vector<Refurbishment> listOfChores);
	void listAllMyChores(std::vector<Refurbishment> listOfChores, int lengthOfTheList);
};