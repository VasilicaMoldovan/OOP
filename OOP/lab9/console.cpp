#include "console.h"
#include <iostream>
#include <typeinfo>
using namespace std;


Refurbishment TaskConsole::uiAddOrUpdateTask(char* token, std::string title, std::string date, std::string mirrorImage, std::string type, int numberOfRepetitions) {
	/*
		Function which reads the the atributes an refurbishment which is added or updated
		Input:
	*/
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
	Refurbishment currentTask = Refurbishment(title, type, date, numberOfRepetitions, mirrorImage);
	return currentTask;
}

void TaskConsole::listAllRefurbishments(char listToBePrinted[]) {
	std::vector<Refurbishment> tasksToPrint = this->consoleVectorModeA.getAllRefurbishments();
	for (auto element : tasksToPrint ){
		cout << element.toString() << "\n";
	}
}

void TaskConsole::listAllRefurbishmentsWithProperty(std::vector<Refurbishment> listOfChores) {
	for (auto chore : listOfChores) {
		cout << chore.toString() << "\n";
	}
}

void TaskConsole::listAllMyChores(std::vector<Refurbishment> listOfChores, int lengthOfTheList) {
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
	string exceptions, extension;
	char *token;
	
	for (int index = 0; index < 2; index++) {
		cin.getline(mode, 256);
		token = strtok(mode, "\n");
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
					this->consoleVectorModeA.setRepositoryType("txt");
					this->consoleVectorModeA.readRepositoryFromFile(token);
					//this->consoleVectorModeA.setRepositoryType("txt");
				}
				else {
					if (strcmp(token, "mylistLocation") == 0) {
						token = strtok(NULL, ".");
						std::string path = token;
						token = strtok(NULL, "\n");
						this->consoleVectorModeA.setRepositoryType(token);
						path += ".";
						path += token;
						this->consoleVectorModeA.savePath(path);
						//this->consoleVectorModeA.saveExtension(token);
						extension = token;
					}
					else
						return;
				}
			}
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
					Refurbishment newTask = uiAddOrUpdateTask(token, title, date, mirrorImage, type, numberOfRepetitions);
					if (strcmp(command, "add") == 0) {
						try {
							this->consoleVectorModeA.addNewRefurbishment(newTask);
							this->consoleVectorModeA.writeRepoToFile();
						}
						catch (RefurbishmentException& error)
						{
							cout << error.getErrorMessage();
						}
					}
					else {
						try {
							this->consoleVectorModeA.updateExistingRefurbishment(newTask);
							this->consoleVectorModeA.writeRepoToFile();
						}
						catch (RefurbishmentException& error)
						{
							cout << error.getErrorMessage();
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
						Refurbishment newTask = Refurbishment(title, type, date, numberOfRepetitions, mirrorImage);
						if (strcmp(typeid(title).name(), "int") != 0) {
							try {
								this->consoleVectorModeA.deleteRefurbishment(newTask);
								this->consoleVectorModeA.writeRepoToFile();
							}
							catch (RefurbishmentException& error) {
								cout << error.getErrorMessage();
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
					this->consoleVectorModeA.writeToCSVHtmlFile(extension);
				}
				else {
					if (strcmp(token, "list") == 0) {
						token = strtok(NULL, ",");
						type = token;
						token = strtok(NULL, " ,\n");
						numberOfRepetitions = atoi(token);
						int lengthOfVector = 0;
						std::vector<Refurbishment> listOfChores = this->consoleVectorModeA.listAllChoresOfTypeAndProperty(type, numberOfRepetitions, lengthOfVector);
						listAllRefurbishmentsWithProperty(listOfChores);
					}
					else {
						if (strcmp(token, "exit") == 0) {
							exitCondition = true;
							this->consoleVectorModeA.openFile();
						}
						else
						{
							if (strcmp(token, "mylist") == 0)
								this->consoleVectorModeA.openFile();
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
