#include "controllerIllness.h"

void controllerIllness::addNewIllnesss(Illness newIllness)
{
	this->repoIllness.addIllnesss(newIllness);
}

void controllerIllness::loadFromFileIllness(std::string pathToFile)
{
	this->repoIllness.loadFromFile(pathToFile);
}

std::vector<Illness> controllerIllness::getAllDisorders()
{
	return this->repoIllness.getAll();
}

std::vector<Illness> controllerIllness::searchByNameOrCategory(std::string desorder)
{
	/*
	Function which searches for disorders with a given category or name
	Precondition: disorder - std::string
	Postcondition: returns the vector containing all the disorders with the given property
	*/

	return this->repoIllness.searchIllness(desorder);
}

std::string controllerIllness::showSymtoms(std::string name)
{
	return this->repoIllness.getSymtomsByName(name);
}

controllerIllness::controllerIllness()
{
}


controllerIllness::~controllerIllness()
{
}
