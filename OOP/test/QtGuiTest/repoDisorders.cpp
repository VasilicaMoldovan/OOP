#include "repoDisorders.h"
#include <cstring>
#include <assert.h>

void repoDisorders::addIllnesss(Illness newIllness)
{
	this->illnessVector.push_back(newIllness);
}

void repoDisorders::loadFromFile(std::string pathToFile)
{
	std::ifstream file(pathToFile);
	if (!file.is_open())
		return;
	Illness illness{};
	while (file >> illness)
	{
		addIllnesss(illness);
	}
	file.close();
}

std::vector<Illness> repoDisorders::getAll()
{
	return this->illnessVector;
}

std::vector<Illness> repoDisorders::searchIllness(std::string disorder)
{
	/*
	Function which searches for disorders with a given category or name
	Precondition: disorder - std::string
	Postcondition: returns the vector containing all the disorders with the given property
	*/
	std::vector<Illness> result;
	char *auxDisorder;
	strcpy(auxDisorder, disorder.c_str());
	char *auxElemName, *auxElemCategory;
	for (auto elem : this->illnessVector)
	{
		strcpy(auxElemCategory, elem.getCategory().c_str());
		strcpy(auxElemName, elem.getName().c_str());

		if (strstr(auxElemCategory, auxDisorder) || strstr(auxElemName, auxDisorder))
			result.push_back(elem);
	}
	return result;
}

std::string repoDisorders::getSymtomsByName(std::string name)
{
	//Illness ill;
	for (auto elem : this->illnessVector)
	{
		if (elem.getName() == name)
		{
			return elem.getName();
		}
	}
}


repoDisorders::repoDisorders()
{
}


repoDisorders::~repoDisorders()
{
}

void Test::testAll()
{
	std::string name, category, symtoms;
	name = "dis1";
	category = "categ1";
	symtoms = "newS";
	Illness newIllness(category, name, symtoms);
	this->illnessVector.addIllnesss(newIllness);
	name = "dis2";
	category = "categ1";
	symtoms = "newS";
	std::vector<Illness> results = this->illnessVector.searchIllness(category);
	assert(results.size() == 2);
	std::vector<Illness> results = this->illnessVector.searchIllness(symtoms);
	assert(results.size() == 0);
	std::vector<Illness> results = this->illnessVector.searchIllness(name);
	assert(results.size() == 1);


}
