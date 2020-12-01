#include <string.h>
#include "Domain.h"

Substance* createSubstance(int catalogingNumber, char *state, char *intendedUse, int potency){
	Substance *newSubstance;

	newSubstance = (Substance*)malloc(sizeof(Substance));
	newSubstance->catalogingNumber = catalogingNumber;

	newSubstance->state = (char*)malloc(sizeof(char) * 64);
	newSubstance->intendedUse = (char*)malloc(sizeof(char) * 64);
	strcpy(newSubstance->state, state);
	strcpy(newSubstance->intendedUse, intendedUse);

	newSubstance->potency = potency;
	
	return newSubstance;
}

int equalSubstances(Substance* firstSubstance, Substance* secondSubstance){
	if (firstSubstance->catalogingNumber == secondSubstance->catalogingNumber)
		return 1;
	else
		return 0;
}

void delete(Substance* ingredient) {
	free(ingredient->intendedUse);
	free(ingredient->state);
	free(ingredient);
}