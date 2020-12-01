#pragma once
#include "controller.h"

class TaskConsole {
private:
	TaskControllerModeA consoleVectorModeA;
public:
	TaskConsole() {};
	void run();
	TElem uiAddOrUpdateTask(char* token, std::string title, std::string date, std::string mirrorImage, std::string type, int numberOfRepetitions);
	bool validInput(std::string title, std::string date, std::string mirrorImage, std::string type, int numberOfRepetitions);
	void listAllRefurbishments(char listToBePrinted[]);
	void listAllRefurbishmentsWithProperty(std::vector<TElem> listOfChores);
	void listAllMyChores(std::vector<TElem> listOfChores, int lengthOfTheList);
};