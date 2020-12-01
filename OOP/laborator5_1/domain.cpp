#include "domain.h"
#include <cstring>
#include <iostream>

Refurbishment::Refurbishment(): title(), type(), date(), numberOfRepetitions(0), mirrorImage() {}

Refurbishment::Refurbishment(char title[], char type[], char date[], int numberOfRepetitions, char mirrorImage[]) {
	this->title = new char[strlen(title) + 1];
	this->type = new char[strlen(type) + 1];
	this->date = new char[strlen(date) + 1];
	this->mirrorImage = new char[strlen(mirrorImage) + 1];
	strcpy(this->title, title);
	strcpy(this->type, type);
	strcpy(this->date, date);
	strcpy(this->mirrorImage, mirrorImage);

	this->numberOfRepetitions = numberOfRepetitions;
}

void Refurbishment::setTitle(char title[]) {
	strcpy(this->title, title);
}

void Refurbishment::setType(char type[]) {
	strcpy(this->type, type);
}

void Refurbishment::setDate(char date[]) {
	strcpy(this->date, date);
}

void Refurbishment::setNumberOfRepetitions(int numberOfRepetitions) {
	this->numberOfRepetitions = numberOfRepetitions;
}

std::string Refurbishment::toString() {
	char choreToPrint[100];
	std::string stringToPrint;
	char buffer[15];
	strcpy(choreToPrint, "");
	strcat(choreToPrint, "Title: ");
	strcat(choreToPrint, this->title);
	strcat(choreToPrint, ", Type: ");
	strcat(choreToPrint, this->type);
	strcat(choreToPrint, ", Last performed: ");
	strcat(choreToPrint, this->date);
	strcat(choreToPrint, ", Times performed: ");
	_itoa(this->numberOfRepetitions, buffer, 10);
	strcat(choreToPrint, buffer);
	strcat(choreToPrint, ", Vision: ");
	strcat(choreToPrint, this->mirrorImage);
	//strcat(choreToPrint, "\n");
	//choreToPrint[strlen(choreToPrint)] = NULL;
	stringToPrint = choreToPrint;
	return stringToPrint;
}
void Refurbishment::setMirrorImage(char mirrorImage[]) {
	strcpy(this->mirrorImage, mirrorImage);
}

char* Refurbishment::getTitle() {
	return this->title;
}

char* Refurbishment::getType() {
	return this->type;
}

char* Refurbishment::getDate() {
	return this->date;
}

int Refurbishment::getNumberOfRepetitions() {
	return this->numberOfRepetitions;
}

char* Refurbishment::getMirrorImage() {
	return this->mirrorImage;
}