#include "Tests.h"
#include <assert.h>

void testDomain() {
	int catalogingNumber = 0;
	int potency = 0;
	char state[100];
	char intendedUse[100];

	Substance* newSubstance = createSubstance(23, "powders", "medicinal", 4);
	Substance* otherSubstance = createSubstance(19, "solids", "alchemical", 4);
	assert(newSubstance->potency == otherSubstance->potency);
	assert(equalSubstances(newSubstance, otherSubstance) == 0);
	strcpy(state, "solids");
	assert(strcmp(otherSubstance->state, state) == 0);
	strcpy(intendedUse, "medicinal");
	assert(strcmp(newSubstance->intendedUse, intendedUse) == 0);
	Substance* thirdSubstance = createSubstance(23, "viscous", "practical", 18);
	assert(equalSubstances(newSubstance, thirdSubstance) == 1);
	catalogingNumber = 19;
	assert(catalogingNumber == otherSubstance->catalogingNumber);
	potency = 18;
	assert(potency == thirdSubstance->potency);
	deleteMemory(newSubstance);
	deleteMemory(otherSubstance);
}

void testRepository() {
	SubstanceRepository* repositoryTest;
	repositoryTest = createRepository();
	int catalogingNumber;
	int potency;
	char state[100];
	char intendedUse[100];
	char errors[200];
	strcpy(errors, "");

	catalogingNumber = 3;
	potency = 17;
	strcpy(state, "powders");
	strcpy(intendedUse, "medicinal");
	Substance* newSubstance;
	newSubstance = createSubstance(catalogingNumber, state, intendedUse, potency);
	addSubstance(newSubstance, errors, repositoryTest);
	assert(strlen(errors) == 0);
	addSubstance(newSubstance, errors, repositoryTest);
	assert(strlen(errors) != 0);
	strcpy(state, "solids");
	newSubstance = createSubstance(catalogingNumber, state, intendedUse, potency);
	updateSubstance(newSubstance, errors, repositoryTest);
	assert(strcmp(repositoryTest->vectorOfSubstances[0]->state, "solids") == 0);
	assert(strcmp(repositoryTest->vectorOfSubstances[0]->intendedUse, "medicinal") == 0);
	Substance* secondSubstance;
	secondSubstance = createSubstance(78, "powders", "practical", 13);
	addSubstance(secondSubstance, errors, repositoryTest);
	deleteSubstance(newSubstance, errors, repositoryTest);
	assert(repositoryTest->vectorOfSubstances[0]->potency == 13);
	assert(strcmp(repositoryTest->vectorOfSubstances[0]->intendedUse, "practical") == 0); 
	deallocateRepository(repositoryTest);
}

void testController() {
	SubstancesController* controllerTest;
	controllerTest = createController();

	int catalogingNumber;
	int potency;
	char state[100];
	char intendedUse[100];
	char errors[200];
	strcpy(errors, "");

	catalogingNumber = 19;
	potency = 78;
	strcpy(state, "liquids");
	strcpy(intendedUse, "alchemical");

	Substance* newSubstance;
	newSubstance = createSubstance(catalogingNumber, state, intendedUse, potency);

	addNewIngredient(errors, newSubstance, controllerTest);
	assert(controllerTest->substancesRepo->vectorOfSubstances[0]->catalogingNumber == 19);
	assert(controllerTest->substancesRepo->vectorOfSubstances[0]->potency == 78);
	assert(strcmp(controllerTest->substancesRepo->vectorOfSubstances[0]->state, "liquids") == 0);
	deleteIngredient(errors, newSubstance, controllerTest);
	assert(controllerTest->substancesRepo->lengthOfVector == 0);
	undoOperation(errors, controllerTest);
	assert(controllerTest->substancesRepo->vectorOfSubstances[0]->catalogingNumber == 19);
	assert(strcmp(controllerTest->substancesRepo->vectorOfSubstances[0]->state, "liquids") == 0);
	redoOperation(errors, controllerTest);
	assert(controllerTest->substancesRepo->lengthOfVector == 0);
	addNewIngredient(errors, newSubstance, controllerTest);
	newSubstance = createSubstance(catalogingNumber, "powders", "medicinal", potency);
	updateIngredient(errors, newSubstance, controllerTest);
	int lengthOfVector = controllerTest->substancesRepo->lengthOfVector - 1;
	assert(strcmp(controllerTest->substancesRepo->vectorOfSubstances[lengthOfVector]->state, "powders") == 0);
	assert(strcmp(controllerTest->substancesRepo->vectorOfSubstances[lengthOfVector]->intendedUse, "medicinal") == 0);
	deallocateController(controllerTest);
}

void runTests() {
	testDomain();
	testRepository();
	testController();
}