#include <stdio.h>
#include <stdlib.h>
#include "Repository.h"

int existingSubstance(TElem* substance, SubstanceRepository *repositoryList) {
	for (int index = 0; index < repositoryList->lengthOfVector; index++) {
		if (equalSubstances(substance, repositoryList->vectorOfSubstances[index]))
			return index;
	}
	return -1;
}

void addSubstance(TElem* substance, char** errorString, SubstanceRepository *repositoryList) {
	if (existingSubstance(substance, repositoryList) != -1)
		strcpy(errorString, "This substance already exists in the apothecary!\n");
	else {
		if (repositoryList->lengthOfVector == repositoryList->capacityOfVector) {
			repositoryList->capacityOfVector *= 1.5;
			repositoryList->vectorOfSubstances = (TElem **)realloc(repositoryList->vectorOfSubstances, sizeof(TElem *) *repositoryList->capacityOfVector);
		}
		else {
			repositoryList->vectorOfSubstances[repositoryList->lengthOfVector] = substance;
			repositoryList->lengthOfVector += 1;
		}
	}
}

void updateSubstance(TElem* substance, char** errorString, SubstanceRepository *repositoryList) {
	int indexOfSubstance = existingSubstance(substance, repositoryList);
	if (indexOfSubstance == -1)
		strcpy(errorString, "The required substance does not exist!\n");
	else {
		repositoryList->vectorOfSubstances[indexOfSubstance]->catalogingNumber = substance->catalogingNumber;
		repositoryList->vectorOfSubstances[indexOfSubstance]->intendedUse = substance->intendedUse;
		repositoryList->vectorOfSubstances[indexOfSubstance]->state = substance->state;
		repositoryList->vectorOfSubstances[indexOfSubstance]->potency = substance->potency;
	}
}

void deleteSubstance(TElem* substance, char** errorString, SubstanceRepository *repositoryList) {
	int indexOfSubstance = existingSubstance(substance, repositoryList);
	if (indexOfSubstance == -1)
		strcpy(errorString, "The required substance does not exist!\n");
	else {
		for (int newIndex = indexOfSubstance; newIndex < repositoryList->lengthOfVector - 1; newIndex++)
			repositoryList->vectorOfSubstances[newIndex] = repositoryList->vectorOfSubstances[newIndex + 1];
		repositoryList->lengthOfVector--;
	}
}

void createStringToPrint(char** stringToBePrinted, SubstanceRepository *repositoryList, int index) {
	char buffer[15];
	strcat(stringToBePrinted, "Cataloging Number: ");
	_itoa(repositoryList->vectorOfSubstances[index]->catalogingNumber, buffer, 10);
	strcat(stringToBePrinted, buffer);
	strcat(stringToBePrinted, " State: ");
	strcat(stringToBePrinted, repositoryList->vectorOfSubstances[index]->state);
	strcat(stringToBePrinted, ", Intended Use: ");
	strcat(stringToBePrinted, repositoryList->vectorOfSubstances[index]->intendedUse);
	strcat(stringToBePrinted, ", Potency: ");
	_itoa(repositoryList->vectorOfSubstances[index]->potency, buffer, 10);
	strcat(stringToBePrinted, buffer);
	strcat(stringToBePrinted, "\n");
}

void listSubstances(char** stringToBePrinted, SubstanceRepository *repositoryList) {
	strcpy(stringToBePrinted, "");
	for (int index = 0; index < repositoryList->lengthOfVector; index++) {
		createStringToPrint(stringToBePrinted, repositoryList, index);
	}
}

void listIntendedUseSubstances(char** stringToBePrinted, char* typeOfFilter, char* intendedUse, SubstanceRepository *repositoryList) {
	strcpy(stringToBePrinted, "");
	for (int index = 0; index < repositoryList->lengthOfVector; index++) {
		if (strcmp(typeOfFilter, "state") == 0) {
			if (strstr(repositoryList->vectorOfSubstances[index]->state, intendedUse) != NULL) {
				createStringToPrint(stringToBePrinted, repositoryList, index);
			}
		}
		else {
			if (strstr(repositoryList->vectorOfSubstances[index]->intendedUse, intendedUse) != NULL) {
				createStringToPrint(stringToBePrinted, repositoryList, index);
			}
		}
	}
}


void deallocateRepository(SubstanceRepository *repositoryList) {
	for (int index = 0; index < repositoryList->lengthOfVector; index++) {
		deleteMemory(repositoryList->vectorOfSubstances[index]);
	}
	free(repositoryList->vectorOfSubstances);
	free(repositoryList);
}

SubstanceRepository* createRepository() {
	SubstanceRepository* repositoryList = (SubstanceRepository*)malloc(sizeof(SubstanceRepository));
	repositoryList->lengthOfVector = 0;
	repositoryList->capacityOfVector = 200;
	repositoryList->vectorOfSubstances = (TElem**)malloc(repositoryList->capacityOfVector* sizeof(TElem*));
	
	return repositoryList;
}

int compareCatalogingNumberValues(TElem* firstSubstance, TElem* secondSubstance) {
	if (firstSubstance->catalogingNumber <= secondSubstance->catalogingNumber)
		return 1;
	return 0;
}

int compareCatalogingNumberValuesDescending(TElem* firstSubstance, TElem* secondSubstance) {
	if (firstSubstance->catalogingNumber >= secondSubstance->catalogingNumber)
		return 1;
	return 0;
}


int compareStateValues(TElem* firstSubstance, TElem* secondSubstance) {
	if (strcmp(firstSubstance->state, secondSubstance->state) <= 0)
		return 1;
	return 0;
}

int compareIntendedUseValues(TElem* firstSubstance, TElem* secondSubstance) {
	if (strcmp(firstSubstance->intendedUse, secondSubstance->intendedUse) <= 0) 
		return 1;
	return 0;
}

int compareIntendedUseValuesDescending(TElem* firstSubstance, TElem* secondSubstance) {
	if (strcmp(firstSubstance->intendedUse, secondSubstance->intendedUse) >= 0)
		return 1;
	return 0;
}

int comparePotencyValues(TElem* firstSubstance, TElem* secondSubstance) {
	if (firstSubstance->potency <= secondSubstance->potency)
		return 1;
	return 0;
}

int comparePotencyValuesDescending(TElem* firstSubstance, TElem* secondSubstance) {
	if (firstSubstance->potency >= secondSubstance->potency)
		return 1;
	return 0;
}


void sortMaximumPotencyValue(int(*relation)(TElem* firstSubstance, TElem* secondSubstance), char** stringToBePrinted, int maximumPotencyValue, SubstanceRepository *repositoryList){
	TElem **listOfSubstances;
	int lengthOfListOfSubstances = 0;
	listOfSubstances = (TElem**)malloc(repositoryList->capacityOfVector * sizeof(TElem*));
	for (int index = 0; index < repositoryList->lengthOfVector; index++) {
		if (repositoryList->vectorOfSubstances[index]->potency < maximumPotencyValue) {
			listOfSubstances[lengthOfListOfSubstances] = repositoryList->vectorOfSubstances[index];
			lengthOfListOfSubstances++;
		}
	}
	for (int index = 0; index < lengthOfListOfSubstances - 1; index++) {
		for (int secondIndex = index + 1; secondIndex < lengthOfListOfSubstances; secondIndex++) {
			if (!relation(listOfSubstances[index]->potency, listOfSubstances[secondIndex]->potency)) {
				TElem* auxiliarySubstance = createSubstance(listOfSubstances[index]->catalogingNumber, listOfSubstances[index]->state, listOfSubstances[index]->intendedUse, listOfSubstances[index]->potency);
				listOfSubstances[index] = listOfSubstances[secondIndex];
				listOfSubstances[secondIndex] = auxiliarySubstance;
				deleteMemory(auxiliarySubstance);
			}
		}
	}
	//qsort(listOfSubstances, lengthOfListOfSubstances, sizeof(TElem), comparePotencyValues);
	listMaximumPotencyValue(stringToBePrinted, listOfSubstances, lengthOfListOfSubstances);
	
	int index;
	for (index = 0; index < lengthOfListOfSubstances; index++) {
		deleteMemory(listOfSubstances[index]);
	}
	free(listOfSubstances);
}

void listMaximumPotencyValue(char** stringToBePrinted, TElem **vectorOfSubstances, int lengthOfVectorOfSubstances) {
	char buffer[15];
	strcpy(stringToBePrinted, "");
	for (int index = 0; index < lengthOfVectorOfSubstances; index++) {
		strcat(stringToBePrinted, "Cataloging Number: ");
		_itoa(vectorOfSubstances[index]->catalogingNumber, buffer, 10);
		strcat(stringToBePrinted, buffer);
		strcat(stringToBePrinted, " State: ");
		strcat(stringToBePrinted, vectorOfSubstances[index]->state);
		strcat(stringToBePrinted, ", Intended Use: ");
		strcat(stringToBePrinted, vectorOfSubstances[index]->intendedUse);
		strcat(stringToBePrinted, ", Potency: ");
		_itoa(vectorOfSubstances[index]->potency, buffer, 10);
		strcat(stringToBePrinted, buffer);
		strcat(stringToBePrinted, "\n");
	}
}

void searchSubstance(TElem* substance, int catalogingNumber, SubstanceRepository *repositoryList) {
	for (int index = 0; index < repositoryList->lengthOfVector; index++) {
		if (repositoryList->vectorOfSubstances[index]->catalogingNumber == catalogingNumber) {
			substance->catalogingNumber = catalogingNumber;
			substance->potency = repositoryList->vectorOfSubstances[index]->potency;
			strcpy(substance->state, repositoryList->vectorOfSubstances[index]->state);
			strcpy(substance->intendedUse, repositoryList->vectorOfSubstances[index]->intendedUse);
			break;
		}
	}
}