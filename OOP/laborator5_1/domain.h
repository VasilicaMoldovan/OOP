#pragma once
#include <string>
//typedef Refurbishment TElem;

class Refurbishment {
private:
	char *title;
	char *type;
	char *date;
	int numberOfRepetitions;
	char *mirrorImage;
public:
	Refurbishment();
	Refurbishment(char title[], char type[], char date[], int numberOfRepetitions, char mirrorImage[]);
	char* getTitle();
	char* getType();
	char* getDate();
	int getNumberOfRepetitions();
	char* getMirrorImage();
	void setTitle(char title[]);
	void setType(char type[]);
	void setDate(char date[]);
	void setNumberOfRepetitions(int numberOfRepetitions);
	void setMirrorImage(char mirrorImage[]);
	std::string toString();
	//~Refurbishment();
};