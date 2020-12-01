#include "console.h"
#include <iostream>
#include <typeinfo>
using namespace std;


TElem TaskConsole::uiAddOrUpdateTask(char* token, std::string title, std::string date, std::string mirrorImage, std::string type, int numberOfRepetitions) {
	token = strtok(NULL, ",\n ");
	title = token;
	token = strtok(NULL, ",\n");
	type = token;
	token = strtok(NULL, " ,\n");
	date = token;
	token = strtok(NULL, " ,\n");
	numberOfRepetitions = atoi(token);
	token = strtok(NULL, ",\n");
	mirrorImage = token;
	TElem currentTask = TElem(title, type, date, numberOfRepetitions, mirrorImage);
	return currentTask;
}

bool TaskConsole::validInput(std::string title, std::string date, std::string mirrorImage, std::string type, int numberOfRepetitions) {
	int nonvalid = 0;
	if (strcmp(typeid(title).name(), "int") == 0 || strcmp(typeid(type).name(), "int") == 0)
		nonvalid++;
	if (strcmp(typeid(date).name(), "int") == 0 || strcmp(typeid(mirrorImage).name(), "int") == 0)
		nonvalid++;
	if (strcmp(typeid(numberOfRepetitions).name(), "int") != 0)
		nonvalid++;
	if (nonvalid)
		return false;
	return true;
}

void TaskConsole::listAllRefurbishments(char listToBePrinted[]) {
	std::vector<TElem> tasksToPrint = this->consoleVectorModeA.getAllRefurbishments();
	for (auto element : tasksToPrint ){
		cout << element.toString() << "\n";
	}
}

void TaskConsole::listAllRefurbishmentsWithProperty(std::vector<TElem> listOfChores) {
	for (auto chore : listOfChores) {
		cout << chore.toString() << "\n";
	}
}

void TaskConsole::listAllMyChores(std::vector<TElem> listOfChores, int lengthOfTheList) {
	for (auto chore : listOfChores) {
		cout << chore.toString() << "\n";
	}
}

void TaskConsole::run() {
	char command[250];
	int numberOfRepetitions = 0;
	int numberOfNexts = 0;
	bool exitCondition = false;
	char mode[256];
	char listToBePrinted[10000];
	int modeToRun = 0;
	string title, date, mirrorImage, type;

	cin.getline(mode, 256);
	char *token = strtok(mode, "\n");
	if (strcmp(token, "mode A") == 0) {
		modeToRun = 1;
	}
	else {
		if (strcmp(token, "mode B") == 0) {
			modeToRun = 2;
		}
		else
		{
			token = strtok(mode, " ,\n");
			if (strcmp(token, "fileLocation") == 0) {
				token = strtok(NULL, "\n");
				this->consoleVectorModeA.readRepositoryFromFile(token);
			}
			else
				return;

		}
	}

	while (!exitCondition) {
		cin.getline(command, 100);
		token = strtok(command, " ,");
		if (strcmp(token, "mode") == 0) {
			token = strtok(NULL, " ,");
			if (strcmp(token, "A") == 0)
				modeToRun = 1;
			else {
				if (strcmp(token, "B") == 0)
					modeToRun = 2;
				else
					return;
			}
		}
		else {
			if (modeToRun == 1) {
				if (strcmp(token, "add") == 0 || strcmp(token, "update") == 0) {
					strcpy(command, token);
					TElem newTask = uiAddOrUpdateTask(token, title, date, mirrorImage, type, numberOfRepetitions);
					if (validInput(title, date, mirrorImage, type, numberOfRepetitions)) {
						if (strcmp(command, "add") == 0) {
							try {
								this->consoleVectorModeA.addNewRefurbishment(newTask);
								this->consoleVectorModeA.writeRepoToFile();
							}
							catch (const char* error)
							{
								cout << error << "\n";
							}
						}
						else {
							try {
								this->consoleVectorModeA.updateExistingRefurbishment(newTask);
								this->consoleVectorModeA.writeRepoToFile();
							}
							catch (const char* error)
							{
								cout << error << "\n";
							}
						}
					}
				}
				else {
					if (strcmp(token, "delete") == 0) {
						token = strtok(NULL, " ,");
						title = token;
						type = "";
						date = "";
						mirrorImage = "";
						numberOfRepetitions = 0;
						TElem newTask = TElem(title, type, date, numberOfRepetitions, mirrorImage);
						if (strcmp(typeid(title).name(), "int") != 0) {
							try {
								this->consoleVectorModeA.deleteRefurbishment(newTask);
								this->consoleVectorModeA.writeRepoToFile();
							}
							catch (const char* error) {
								cout << error << "\n";
							}
						}
					}
					else {
						if (strcmp(token, "list") == 0) {
							listAllRefurbishments(listToBePrinted);
						}
						else {
							if (strcmp(token, "exit") == 0)
								exitCondition = true;
							else
								cout << "Invalid input\n";
						}
					}
				}
			}
			else{
				if (strcmp(token, "next") == 0) {
					cout << this->consoleVectorModeA.seeNextChore(numberOfNexts).toString() << "\n";
					numberOfNexts++;
					if (numberOfNexts == this->consoleVectorModeA.getNumberOfRefurbishments())
						numberOfNexts = 0;
				}
				else {
					if (strcmp(token, "save") == 0) {
						token = strtok(NULL, " \n");
						title = token;
						this->consoleVectorModeA.saveCurrentChore(title);
					}
					else {
						if (strcmp(token, "list") == 0) {
							token = strtok(NULL, ",");
							type = token;
							token = strtok(NULL, " ,\n");
							numberOfRepetitions = atoi(token);
							int lengthOfVector = 0;
							std::vector<TElem> listOfChores = this->consoleVectorModeA.listAllChoresOfTypeAndProperty(type, numberOfRepetitions, lengthOfVector);
							listAllRefurbishmentsWithProperty(listOfChores);
						}
						else {
							if (strcmp(token, "mylist") == 0) {
								int lengthOfVector = 0;
								std::vector<TElem> listOfChores = this->consoleVectorModeA.getAllSavedChores(lengthOfVector);
								listAllMyChores(listOfChores, lengthOfVector);
							}
							else {
								if (strcmp(token, "exit") == 0)
									exitCondition = true;
								else
									cout << "Invalid input!\n";
							}
						}
					}
				}
			}
		}
	}
	this->consoleVectorModeA.writeRepoToFile();
}
