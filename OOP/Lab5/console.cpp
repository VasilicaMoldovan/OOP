#include "console.h"
#include <iostream>
#include <typeinfo>
using namespace std;

TElem TaskConsole::uiAddOrUpdateTask(char* token, char title[], char date[], char mirrorImage[], char type[], int numberOfRepetitions) {
	token = strtok(NULL, ",");
	strcpy(title, token);
	token = strtok(NULL, ",");
	strcpy(type, token);
	token = strtok(NULL, ",");
	strcpy(date, token);
	token = strtok(NULL, ",");
	numberOfRepetitions = atoi(token);
	token = strtok(NULL, ",");
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


void TaskConsole::run() {
	char command[250];
	char title[100], date[100], mirrorImage[100], type[100];
	int numberOfRepetitions = 0;
	bool exitCondition = false;
	char mode[100];
	char listToBePrinted[10000];
	strcpy(title, "");
	strcpy(type, "");
	strcpy(date, "");
	strcpy(mirrorImage, "");


	cin.getline(mode, 100);
	char *token = strtok(mode, "\n");
	if (strcmp(mode, "mode A") == 0) {
		while (!exitCondition) {
			cin.getline(command, 100);
			char *token = strtok(command, " ,");
			if (strcmp(token, "add") == 0 || strcmp(token, "update") == 0) {
				strcpy(command, token);
				TElem newTask = uiAddOrUpdateTask(token, title, date, mirrorImage, type, numberOfRepetitions);
				if (validInput(title, date, mirrorImage, type, numberOfRepetitions)) {
					if (strcmp(command, "add") == 0) {
						try {
							this->consoleVectorModeA.addNewRefurbishment(newTask);
						}
						catch (const char* e)
						{
							cout << e << "\n";
						}
					}
					else {
						try {
							this->consoleVectorModeA.updateExistingRefurbishment(newTask);
						}
						catch (const char* e)
						{
							cout << e << "\n";
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
						catch (const char* e) {
							cout << e << "\n";
						}
					}
				}
				else {
					if (strcmp(token, "list") == 0) {
						this->consoleVectorModeA.listAllRefurbishments(listToBePrinted);
						cout << listToBePrinted;
					}
					else {
						if (strcmp(token, "exit") == 0)
							exitCondition = true;
						else
							cout << "Invalid input";
					}
				}
			}
		}
	}
	else {
		cout << "Invalid mode";
	}
}
