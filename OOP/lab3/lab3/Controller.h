#pragma once
//#include "Repository.h"
#include "undoRedo.h"

typedef struct {
	SubstanceRepository* substancesRepo;
	UndoRedo* undoController;
}SubstancesController;

void addNewIngredient(char** errorString, Substance* substance, SubstancesController *controller);
void updateIngredient(char** errorString, Substance* substance, SubstancesController *controller);
void deleteIngredient(char** errorString, Substance* substance, SubstancesController *controller);
void listIngredients(char** finalList, SubstancesController *controller);
void listIntendedUseIngredients(char** finalList, char* intendedUse, SubstancesController *controller);
void listStateIngredients(char** finalList, char* state, SubstancesController *controller);
void deallocateController(SubstancesController* controller);
SubstancesController* createController();
void listMaximumPotencyValueIngredients(char** finalList, int maximumPotencyValue, SubstancesController *controller);
void listMaximumPotencyValueIngredientsDescending(char** finalList, int maximumPotencyValue, SubstancesController *controller);
void undoOperation(char** finalList, SubstancesController *controller);
void redoOperation(char** finalList, SubstancesController *controller);