#include "domain.h"
#include <cstring>

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
/*
Refurbishment::~Refurbishment() {
	delete[] this->title;
	delete[] this->type;
	delete[] this->date;
	delete[] this->mirrorImage;
	//delete[] this->numberOfRepetitions;
}*/