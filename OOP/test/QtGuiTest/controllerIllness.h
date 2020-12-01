#pragma once
#include "repoDisorders.h"

class controllerIllness
{
private:
	repoDisorders repoIllness;
public:
	controllerIllness();
	void addNewIllnesss(Illness newIllness);
	void loadFromFileIllness(std::string pathToFile);
	std::vector<Illness> getAllDisorders();
	std::vector<Illness> searchByNameOrCategory(std::string desorder);
	std::string showSymtoms(std::string name);
	~controllerIllness();
};

