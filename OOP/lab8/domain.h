#pragma once
#include <string>
#include <vector>

//typedef Refurbishment TElem;

class Refurbishment {
private:
	std::string title;
	std::string type;
	std::string date;
	int numberOfRepetitions;
	std::string mirrorImage;
public:
	Refurbishment();
	Refurbishment(std::string title, std::string type, std::string date, int numberOfRepetitions, std::string mirrorImage);
	//Refurbishment(std::string const title, std::string const type, std::string const date, int const numberOfRepetitions, std::string const mirrorImag);

	std::string getTitle();
	std::string getType();
	std::string getDate();
	int getNumberOfRepetitions();
	std::string getMirrorImage();
	void setTitle(std::string title);
	void setType(std::string type);
	void setDate(std::string date);
	void setNumberOfRepetitions(int numberOfRepetitions);
	void setMirrorImage(std::string mirrorImage);
	std::string toString();
	friend std::istream& operator>>(std::istream& is, Refurbishment& task);
	friend std::ostream& operator<<(std::ostream& os, Refurbishment& task);
	//~Refurbishment();
};