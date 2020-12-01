#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Illness
{
private:
	std::string category;
	std::string name;
	std::string symtoms;
public:
	Illness() : category{ "" }, name{ "" }, symtoms{ "" } {}
	Illness(std::string category, std::string name,std::string symtoms);
	std::string getCategory();
	std::string getName();
	std::string getSymptoms();
	std::string toString();
	friend std::istream& operator>>(std::istream& is, Illness& illness);
	~Illness();
};

