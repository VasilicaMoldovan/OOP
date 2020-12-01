#pragma once
#include <stdlib.h>

typedef struct{
	int catalogingNumber;
	char *state;
	char *intendedUse;
	int potency;
}Substance;

Substance* createSubstance(int catalogingNumber, char *state, char *intendedUse, int potency);
void delete(Substance* ingredient);
int equalSubstances(Substance* firstSubstance, Substance* secondSubstance);