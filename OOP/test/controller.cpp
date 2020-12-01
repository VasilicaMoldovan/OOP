#include "controller.h"

bool MicrospritesController::addNewMicrospriteToTheList(Microsprites newMicrosprite) {
	/*
	Function which adds a new population of microsprites
	Input: newMicrosprites - the population that needs to be added to the list
	Output: true - if the population was succesfully added
			false - if the population already exists in the list
	*/
	return this->controllerOfMicrosprites.addNewElementToTheList(newMicrosprite);
}

DynamicVector<Microsprites> MicrospritesController::getAllTheMicrosprites() {
	return this->controllerOfMicrosprites.getAllTheElements();
}

void MicrospritesController::sortMicrosprites() {
	this->controllerOfMicrosprites.sortByType();
}

void MicrospritesController::doubleNumberOfOrganisms() {
	this->controllerOfMicrosprites.doubleNumbers();
}

void MicrospritesController::halveNumberOfOrganisms() {
	this->controllerOfMicrosprites.halveNumbers();
}

void MicrospritesController::modifyPopulationNumber(char type[]) {
	/*
	Function that modifies the number of the population according to the type of the environment
	If the type of the environment is sugar, the function will double the number of organisms, otherwise it will halve it
	Input: type - the type of the environment
	Output: -
	*/
	if (strcmp(type, "sugar") == 0)
		this->controllerOfMicrosprites.doubleNumbers();
	else
		this->controllerOfMicrosprites.halveNumbers();
}

int MicrospritesController::getNumberOfMicrosprites() {
	this->controllerOfMicrosprites.getNumberOfAllElements();
}