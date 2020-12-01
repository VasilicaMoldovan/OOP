#include "domain.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include<Windows.h>
#include <shellapi.h>

Refurbishment::Refurbishment() : title(""), type(""), date(""), numberOfRepetitions(0), mirrorImage("") {}
/*
Refurbishment::Refurbishment(std::string title, std::string type, std::string date, int numberOfRepetitions, std::string mirrorImage) {
	this->title = title;
	this->type = type;
	this->date = date;
	this->numberOfRepetitions = numberOfRepetitions;
	this->mirrorImage = mirrorImage;

}*/

bool Refurbishment::operator==(const Refurbishment& task)
{
	return (this->title == task.title);
}



Refurbishment::Refurbishment(const std::string& title, const std::string& type, const std::string& date,const int& numberOfRepetitions, const std::string&  mirrorImage) {
	this->title = title;
	this->type = type;
	this->date = date;
	this->numberOfRepetitions = numberOfRepetitions;
	this->mirrorImage = mirrorImage;

}


void Refurbishment::setTitle(std::string title) {
	this->title = title;
}

void Refurbishment::setType(std::string type) {
	this->type = type;
}

void Refurbishment::setDate(std::string date) {
	this->date = date;
}

void Refurbishment::setNumberOfRepetitions(int numberOfRepetitions) {
	this->numberOfRepetitions = numberOfRepetitions;
}

std::string Refurbishment::toString() {
	std::string stringToPrint;
	stringToPrint = "Title: " + this->title;
	stringToPrint += ", Type: " + this->type;
	stringToPrint += ", Date: " + this->date;
	std::string auxiliaryString = std::to_string(this->numberOfRepetitions);
	stringToPrint += ", Number of repetitions: " + auxiliaryString;
	stringToPrint += ", Mirror Image: " + this->mirrorImage;
	return stringToPrint;
}
void Refurbishment::setMirrorImage(std::string mirrorImage) {
	this->mirrorImage = mirrorImage;
}

std::string Refurbishment::getTitle() const {
	return this->title;
}

std::string Refurbishment::getType() const {
	return this->type;
}

std::string Refurbishment::getDate() const {
	return this->date;
}

int Refurbishment::getNumberOfRepetitions() const{
	return this->numberOfRepetitions;
}

std::string Refurbishment::getMirrorImage() const{
	return this->mirrorImage;
}


std::vector<std::string> tokenize(std::string stringToBeRead, char delimiter)
{
	std::vector <std::string> result;
	std::stringstream ss(stringToBeRead);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream& operator>>(std::istream& is, Refurbishment& task) {
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the starship data was valid
		return is;
	task.title = tokens[0];
	task.type = tokens[1];
	task.date = tokens[2];
	std::string::size_type sizeType;
	task.numberOfRepetitions = std::stoi(tokens[3], &sizeType);
	task.mirrorImage = tokens[4];

	return is;
}
/*
std::ostream& operator<<(std::ostream& os, Refurbishment& task) {
	os << task.title << "," << task.type << "," << task.date << "," << task.numberOfRepetitions << "," << task.mirrorImage << "\n";
	return os;
}*/