#pragma once
#include "Domain.h"
typedef Substance TElem;

typedef struct{
	TElem **vectorOfSubstances;
	int lengthOfVector;
	int capacityOfVector;
}SubstanceRepository;

int existingSubstance(TElem* substance, SubstanceRepository *repositoryList);
void addSubstance(TElem* substance, char** errorString, SubstanceRepository *repositoryList);
void updateSubstance(TElem* substance, char** errorString, SubstanceRepository *repositoryList);
void deleteSubstance(TElem* substance, char** errorString, SubstanceRepository *repositoryList);
void listSubstances(char** stringToBePrinted, SubstanceRepository *repositoryList);
void listIntendedUseSubstances(char** stringToBePrinted, char* intendedUse, SubstanceRepository *repositoryList);
void deallocateRepository(SubstanceRepository *repositoryList);
SubstanceRepository* createRepo();
void listMaximumPotencyValue(char** stringToBePrinted, TElem **vectorOfSubstances, int lengthOfVectorOfSubstances);
int compareCatalogingNumberValues(TElem* firstSubstance, TElem* secondSubstance);
int compareStateValues(TElem* firstSubstance, TElem* secondSubstance);
int compareIntendedUseValues(TElem* firstSubstance, TElem* secondSubstance);
int comparePotencyValues(TElem* firstSubstance, TElem* secondSubstance);
void sortMaximumPotencyValue(char** stringToBePrinted, int maximumPotencyValue, SubstanceRepository *repositoryList);
void searchSubstance(TElem* substance, int catalogingNumber, SubstanceRepository *repositoryList);