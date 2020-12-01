#include "repo.h"

bool MicrospritesRepository::addNewElementToTheList(Microsprites newMicrosprite) {
	/*
	Function which adds a new population of microsprites
	Input: newMicrosprites - the population that needs to be added to the list
	Output: true - if the population was succesfully added
			false - if the population already exists in the list
	existingElement function returns the position of a given element in the list, or -1 if the element does not exists in the list 
	*/
	if (this->listOfMicrosprites.existingElement(newMicrosprite) == -1) {
		this->listOfMicrosprites.addElement(newMicrosprite);
		return true;
	}
	else
		return false;
}

DynamicVector<Microsprites> MicrospritesRepository::getAllTheElements() {
	return this->listOfMicrosprites;
}

void MicrospritesRepository::sortByType() {
	Microsprites auxiliaryMicrosprites = Microsprites();
	for (int firstIndex = 0; firstIndex < this->listOfMicrosprites.getNumberOfElements() - 1; firstIndex++) {
		for (int secondIndex = firstIndex + 1; secondIndex < this->listOfMicrosprites.getNumberOfElements(); secondIndex++) {
			if (strcmp(this->listOfMicrosprites[firstIndex].getType(), this->listOfMicrosprites[secondIndex].getType()) > 0) {
				auxiliaryMicrosprites = this->listOfMicrosprites[firstIndex];
				this->listOfMicrosprites[firstIndex] = this->listOfMicrosprites[secondIndex];
				this->listOfMicrosprites[secondIndex] = auxiliaryMicrosprites;
			}
		}
	}
}

void MicrospritesRepository::doubleNumbers() {
	int temporaryNumber = 0;
	for (int index = 0; index < this->listOfMicrosprites.getNumberOfElements(); index++) {
		temporaryNumber = this->listOfMicrosprites[index].getNumberOfOrganisms();
		this->listOfMicrosprites[index].setNumberOfOrganisms(2 * temporaryNumber);
	}
}

void MicrospritesRepository::halveNumbers() {
	int temporaryNumber = 0;
	for (int index = 0; index < this->listOfMicrosprites.getNumberOfElements(); index++) {
		if (this->listOfMicrosprites[index].getImmunity() == false) {
			temporaryNumber = this->listOfMicrosprites[index].getNumberOfOrganisms();
			this->listOfMicrosprites[index].setNumberOfOrganisms(temporaryNumber / 2);
		}
	}
}

int MicrospritesRepository::getNumberOfAllElements() {
	return this->listOfMicrosprites.getNumberOfElements();
}