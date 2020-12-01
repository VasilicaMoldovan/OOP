#pragma once
#include "domain.h"
#include "dynamicVector.h"

class MicrospritesRepository {
private:
	DynamicVector<Microsprites> listOfMicrosprites;

public:
	MicrospritesRepository() {};
	bool addNewElementToTheList(Microsprites newMicrosprite);
	DynamicVector<Microsprites> getAllTheElements();
	void sortByType();
	void doubleNumbers();
	void halveNumbers();
	int getNumberOfAllElements();
};