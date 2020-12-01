#include "domain.h"
#include <cstring>

Microsprites::Microsprites(char type[], int numberOfOrganisms, bool immunity) {
	this->type = new char[strlen(type)];
	strcpy(this->type, type);
	this->numberOfOrganisms = numberOfOrganisms;
	this->immunity = immunity;
}

Microsprites::Microsprites() {
	this->type = new char[1];
	strcpy(this->type, "");
	this->numberOfOrganisms = 0;
	this->immunity = false;
}

char* Microsprites::getType() const {
	return this->type;
}

int Microsprites::getNumberOfOrganisms() const {
	return this->numberOfOrganisms;
}

bool Microsprites::getImmunity() const {
	return this->immunity;
}

std::string Microsprites::toString() const {
	char microspriteToPrint[150];
	char buffer[15];
	strcpy(microspriteToPrint, "Type: ");
	strcat(microspriteToPrint, this->type);
	strcat(microspriteToPrint, ", Number of organisms: ");
	_itoa(this->numberOfOrganisms, buffer, 10);
	strcat(microspriteToPrint, buffer);
	strcat(microspriteToPrint, ", Immunity: ");
	if (this->immunity == true )
		strcat(microspriteToPrint, "true");
	else
		strcat(microspriteToPrint, "false");
	std::string stringToPrint;
	stringToPrint = microspriteToPrint;

	return stringToPrint;
}

void Microsprites::setNumberOfOrganisms(int newNumber) {
	this->numberOfOrganisms = newNumber;
}