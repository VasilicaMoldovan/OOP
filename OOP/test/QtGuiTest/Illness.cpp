#include "Illness.h"



Illness::Illness(std::string category, std::string name, std::string symtoms) : category(category), name(name), symtoms(symtoms)
{

}

std::string Illness::getCategory()
{
	return this->category;
}

std::string Illness::getName()
{
	return this->name;
}

std::string Illness::getSymptoms()
{
	return this->symtoms;
}

std::string Illness::toString()
{
	std::string auxString = "";
	auxString += this->category;
	auxString += "/ ";
	auxString += this->name;
	auxString += "/ ";
	auxString += this->symtoms;
	/*for (auto elem : this->symtoms)
	{
		auxString += elem;
		auxString += ", ";
	}*/
	return auxString;
}

std::vector<std::string> tokenize(std::string stringToBeRead, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(stringToBeRead);
	std::string token;
	
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::istream& operator>>(std::istream& is, Illness& illness)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, '/');
	if (tokens.size() != 3)
		return is;
	illness.category = tokens[0];
	illness.name = tokens[1];
	illness.symtoms = tokens[2];
	return is;
}



Illness::~Illness()
{
}
