/*#include "tests.h"
#include <assert.h>

void MicrospritesTest::testAddFunction() {
	assert(this->populationsOfMicrosprites.getNumberOfMicrosprites() == 0);
	char type[100];
	int numberOfOrganisms = 0;
	bool immunity = false;
	strcpy(type, "Woodbores");
	numberOfOrganisms = 100;
	Microsprites newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == true);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == false);
	assert(this->populationsOfMicrosprites.getNumberOfMicrosprites() == 1);
	strcpy(type, "Springseed");
	numberOfOrganisms = 150;
	immunity = true;
	newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == true);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == false);
	assert(this->populationsOfMicrosprites.getNumberOfMicrosprites() == 2);
}

void MicrospritesTest::testModifyFunction() {
	char type[100];
	int numberOfOrganisms = 0;
	bool immunity = false;
	strcpy(type, "Woodbores");
	numberOfOrganisms = 100;
	Microsprites newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == true);
	immunity = true;
	strcpy(type, "Springseed");
	numberOfOrganisms = 150;
	Microsprites newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == true);
	immunity = true;
	strcpy(type, "Microsprite");
	numberOfOrganisms = 56;
	Microsprites newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == true);
	immunity = false;
	strcpy(type, "Another");
	numberOfOrganisms = 28;
	Microsprites newMicrosprites = Microsprites(type, numberOfOrganisms, immunity);
	assert(this->populationsOfMicrosprites.addNewMicrospriteToTheList(newMicrosprites) == true);
	strcpy(type, "sugar");
	int initialNumber[] = { 100, 150, 56, 28 };
	this->populationsOfMicrosprites.modifyPopulationNumber(type);
	DynamicVector<Microsprites> auxiliaryVector = this->populationsOfMicrosprites.getAllTheMicrosprites();
	for (int index = 0; index < auxiliaryVector.getNumberOfElements(); index++) {
		assert(auxiliaryVector[index].getNumberOfOrganisms() == initialNumber[index]); 
	}




}*/