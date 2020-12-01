#pragma once
#include "repo.h"

class MicrospritesController {
private:
	MicrospritesRepository controllerOfMicrosprites;
public:
	MicrospritesController() {};
	bool addNewMicrospriteToTheList(Microsprites newMicrosprite);
	DynamicVector<Microsprites> getAllTheMicrosprites();
	void sortMicrosprites();
	void modifyPopulationNumber(char type[]);
	void doubleNumberOfOrganisms();
	void halveNumberOfOrganisms();
	int getNumberOfMicrosprites();
};