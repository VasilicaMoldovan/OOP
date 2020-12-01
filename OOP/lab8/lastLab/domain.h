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
	//Refurbishment(std::string title, std::string type, std::string date, int numberOfRepetitions, std::string mirrorImage);
	Refurbishment(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage);
	bool operator==(const Refurbishment& task);
	std::string getTitle() const;
	std::string getType() const;
	std::string getDate() const;
	int getNumberOfRepetitions() const;
	std::string getMirrorImage() const;
	void setTitle(std::string title);
	void setType(std::string type);
	void setDate(std::string date);
	void setNumberOfRepetitions(int numberOfRepetitions);
	void setMirrorImage(std::string mirrorImage);
	std::string toString();
	friend std::istream& operator>>(std::istream& is, Refurbishment& task);
	//friend std::ostream& operator<<(std::ostream& os, Refurbishment& task);
	//~Refurbishment();
};