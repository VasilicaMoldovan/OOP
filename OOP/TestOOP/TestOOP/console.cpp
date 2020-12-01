#include "console.h"
#include <iostream>
using namespace std;

void MicrospritesConsole::printAllTheMicrosprites(DynamicVector<Microsprites> vectorOfMicrosprites) {
	for (int index = 0; index < vectorOfMicrosprites.getNumberOfElements(); index++) {
		cout << vectorOfMicrosprites[index].toString() << "\n";
	}
}

void MicrospritesConsole::run() {
	char type[100];
	strcpy(type, "");
	int numberOfOrganisms = 0;
	bool immunity = false;
	bool exitCondition = false;
	char* token;
	char command[150];

	while (!exitCondition) {
		cin.getline(command, 150);
		token = strtok(command, " ,\n");
		if (strcmp(token, "add") == 0) {
			token = strtok(NULL, " ,\n");
			strcpy(type, token);
			token = strtok(NULL, " ,\n");
			numberOfOrganisms = atoi(token);
			token = strtok(NULL, " ,\n");
			if (strcmp(token, "true") == 0)
				immunity = true;
			else
				immunity = false;
			Microsprites newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
			if (this->totalityOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites))
				cout << "Population added succesfully\n";
			else
				cout << "Population already exists in the list\n";
		}
		else {
			if (strcmp(token, "list") == 0) {
				token = strtok(NULL, " ,\n");
				if (token == NULL) {
					printAllTheMicrosprites(this->totalityOfMicrosprites.getAllTheMicrosprites());
				}
				else {
					this->totalityOfMicrosprites.sortMicrosprites();
					printAllTheMicrosprites(this->totalityOfMicrosprites.getAllTheMicrosprites());
				}
			}
			else {
				if (strcmp(token, "sugar") == 0 || strcmp(token, "healing") == 0) {
					this->totalityOfMicrosprites.modifyPopulationNumber(token);
					//this->totalityOfMicrosprites.doubleNumberOfOrganisms();
				}
				else {
					/*
					strcpy(command, token);
					token = strtok(NULL, " ,\n");
					if (strcmp(command, "healing") == 0 && strcmp(token, "balm") == 0)
						this->totalityOfMicrosprites.halveNumberOfOrganisms();
					else {*/
					if (strcmp(command, "exit") == 0)
						exitCondition = true;
					else
						cout << "invalid input\n";
					}
				}
			}
		}
	}