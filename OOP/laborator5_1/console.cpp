#include "console.h"
#include <iostream>
#include <typeinfo>
using namespace std;


TElem TaskConsole::uiAddOrUpdateTask(char* token, char title[], char date[], char mirrorImage[], char type[], int numberOfRepetitions) {
	token = strtok(NULL, ",\n ");
	strcpy(title, token);
	token = strtok(NULL, ",\n");
	strcpy(type, token);
	token = strtok(NULL, ",\n");
	strcpy(date, token);
	token = strtok(NULL, ",\n");
	numberOfRepetitions = atoi(token);
	token = strtok(NULL, ",\n");
	strcpy(mirrorImage, token);
	TElem currentTask = TElem(title, type, date, numberOfRepetitions, mirrorImage);
	return currentTask;
}

bool TaskConsole::validInput(char title[], char date[], char mirrorImage[], char type[], int numberOfRepetitions) {
	int cnt = 0;
	if (strcmp(typeid(title).name(), "int") == 0 || strcmp(typeid(type).name(), "int") == 0)
		cnt++;
	if (strcmp(typeid(date).name(), "int") == 0 || strcmp(typeid(mirrorImage).name(), "int") == 0)
		cnt++;
	if (strcmp(typeid(numberOfRepetitions).name(), "int") != 0)
		cnt++;
	if (cnt)
		return false;
	return true;
}

void TaskConsole::listAllRefurbishments(char listToBePrinted[]) {
	TElem* tasksToPrint = this->consoleVectorModeA.getAllRefurbishments();
	strcpy(listToBePrinted, "");
	char buffer[15];
	for (int index = 0; index < this->consoleVectorModeA.getNumberOfRefurbishments(); index++) {
		strcat(listToBePrinted, "Title: ");
		strcat(listToBePrinted, tasksToPrint[index].getTitle());
		strcat(listToBePrinted, ", Type: ");
		strcat(listToBePrinted, tasksToPrint[index].getType());
		strcat(listToBePrinted, ", Last performed: ");
		strcat(listToBePrinted, tasksToPrint[index].getDate());
		strcat(listToBePrinted, ", Times performed: ");
		_itoa(tasksToPrint[index].getNumberOfRepetitions(), buffer, 10);
		strcat(listToBePrinted, buffer);
		strcat(listToBePrinted, ", Vision: ");
		strcat(listToBePrinted, tasksToPrint[index].getMirrorImage());
		strcat(listToBePrinted, "\n");
	}
}

void TaskConsole::listAllRefurbishmentsWithProperty(DynamicVector<TElem> listOfChores) {
	for (int index = 0; index < listOfChores.getNumberOfElements(); index++) {
		cout << listOfChores[index].toString() << "\n";
	}
	/*
	for (int index = 0; index < lengthOfTheList; index++) {
		cout << listOfChores->toString();
	}*/
}

void TaskConsole::listAllMyChores(TElem* listOfChores, int lengthOfTheList) {
	for (int index = 0; index < lengthOfTheList; index++) {
		cout << listOfChores[index].toString() << "\n";
		//cout << listOfChores->toString() << " ";
	}
}

void TaskConsole::run() {
	char command[250];
	char title[100], date[100], mirrorImage[100], type[100];
	int numberOfRepetitions = 0;
	int numberOfNexts = 0;
	bool exitCondition = false;
	char mode[100];
	char listToBePrinted[10000];
	int modeToRun = 0;
	strcpy(listToBePrinted, "");
	strcpy(title, "");
	strcpy(type, "");
	strcpy(date, "");
	strcpy(mirrorImage, "");

	cin.getline(mode, 100);
	char *token = strtok(mode, "\n");
	if (strcmp(token, "mode A") == 0) {
		modeToRun = 1;
	}
	else {
		if (strcmp(token, "mode B") == 0) {
			modeToRun = 2;
		}
		else
			return;
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
					//modeToRun = 0;
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
							}
							catch (const char* error)
							{
								cout << error << "\n";
							}
						}
						else {
							try {
								this->consoleVectorModeA.updateExistingRefurbishment(newTask);
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
						strcpy(title, token);
						strcpy(type, "");
						strcpy(date, "");
						strcpy(mirrorImage, "");
						numberOfRepetitions = 0;
						TElem newTask = TElem(title, type, date, numberOfRepetitions, mirrorImage);
						if (strcmp(typeid(title).name(), "int") != 0) {
							try {
								this->consoleVectorModeA.deleteRefurbishment(newTask);
							}
							catch (const char* error) {
								cout << error << "\n";
							}
						}
					}
					else {
						if (strcmp(token, "list") == 0) {
							listAllRefurbishments(listToBePrinted);
							cout << listToBePrinted;
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
						strcpy(title, token);
						this->consoleVectorModeA.saveCurrentChore(title);
					}
					else {
						if (strcmp(token, "list") == 0) {
							token = strtok(NULL, ",");
							strcpy(type, token);
							token = strtok(NULL, " ,\n");
							numberOfRepetitions = atoi(token);
							int lengthOfVector = 0;
							DynamicVector<TElem> listOfChores = this->consoleVectorModeA.listAllChoresOfTypeAndProperty(type, numberOfRepetitions, lengthOfVector);
							listAllRefurbishmentsWithProperty(listOfChores);
						}
						else {
							if (strcmp(token, "mylist") == 0) {
								int lengthOfVector = 0;
								TElem* listOfChores = this->consoleVectorModeA.getAllSavedChores(lengthOfVector);
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
}
