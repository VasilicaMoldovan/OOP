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
void deallocateController(SubstancesController* controller);
SubstancesController* createController();
void listSortedVector(char** finalList, int maximumPotencyValue, SubstancesController *controller, char* sortingType);
void listFilteredList(char** finalList, char* property, SubstancesController *controller, char* filteringType);
void undoOperation(char** finalList, SubstancesController *controller);
void redoOperation(char** finalList, SubstancesController *controller);