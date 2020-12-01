#pragma once
#include "Illness.h"
class repoDisorders
{
private:
	std::vector<Illness> illnessVector;
public:
	repoDisorders();
	void addIllnesss(Illness newIllness);
	void loadFromFile(std::string pathToFile);
	std::vector<Illness> getAll();
	std::vector<Illness> searchIllness(std::string disorder);
	std::string getSymtomsByName(std::string name);
	~repoDisorders();
};

class Test {
private:
	repoDisorders illnessVector;
public:
	void testAll();
};

