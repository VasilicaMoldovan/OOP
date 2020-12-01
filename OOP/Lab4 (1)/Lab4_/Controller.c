#include "Controller.h"

void addNewIngredient(char** errorString, Substance* substance, SubstancesController *controller) {
	addSubstance(substance, errorString, controller->substancesRepo);
	UndoOperation *newOperation;
	newOperation = createUndoOperation(substance, substance, addSubstance, deleteSubstance, controller->substancesRepo);
	addNewUndoOperation(newOperation, controller->undoController);
}

void updateIngredient(char** errorString, Substance* substance, SubstancesController *controller) {
	TElem *oldSubstance = createSubstance(0, "", "", 0);
	searchSubstance(oldSubstance, substance->catalogingNumber, controller->substancesRepo);
	updateSubstance(substance, errorString, controller->substancesRepo);
	UndoOperation *newOperation;
	newOperation = createUndoOperation(oldSubstance, substance, updateSubstance, updateSubstance, controller->substancesRepo);
	addNewUndoOperation(newOperation, controller->undoController);
}

void deleteIngredient(char** errorString, Substance* substance, SubstancesController *controller) {
	UndoOperation *newOperation;
	TElem* newSubstance = createSubstance(0, "", "", 0);
	searchSubstance(newSubstance, substance->catalogingNumber, controller->substancesRepo);
	newOperation = createUndoOperation(newSubstance, newSubstance, deleteSubstance, addSubstance, controller->substancesRepo);
	addNewUndoOperation(newOperation, controller->undoController);
	deleteSubstance(substance, errorString, controller->substancesRepo);

}

void listIngredients(char** finalList, SubstancesController *controller) {
	listSubstances(finalList, controller->substancesRepo);
}

void listIntendedUseIngredients(char** finalList, char* intendedUse, SubstancesController *controller) {
	listIntendedUseSubstances(finalList, intendedUse, controller->substancesRepo);
}

void deallocateController(SubstancesController* controller) {
	deallocateRepository(controller->substancesRepo);
	free(controller);
}

SubstancesController* createController() {
	SubstancesController* newController;
	newController = (SubstancesController*)malloc(sizeof(SubstancesController));
	newController->substancesRepo = createRepo();
	newController->undoController = createUndoRedo();

	return newController;
}

void listMaximumPotencyValueIngredients(char** finalList, int maximumPotencyValue, SubstancesController *controller) {
	sortMaximumPotencyValue(finalList, maximumPotencyValue, controller->substancesRepo);
}

void undoOperation(char** finalList, SubstancesController *controller) {
	if (controller->undoController->lengthOfUndoList == 0)
		strcpy(finalList, "No more possible undos!");
	else {
		int numberOfUndos = controller->undoController->lengthOfUndoList;
		TElem* oldSubstance = controller->undoController->undoList[numberOfUndos - 1]->oldSubstance;
		controller->undoController->undoList[numberOfUndos - 1]->inverseOperation(oldSubstance, finalList, controller->substancesRepo);

		int redoLength = controller->undoController->lengthOfRedoList;
		UndoOperation* newOperation = createUndoOperation(controller->undoController->undoList[numberOfUndos - 1]->newSubstance, controller->undoController->undoList[numberOfUndos - 1]->oldSubstance, controller->undoController->undoList[numberOfUndos - 1]->directOperation, controller->undoController->undoList[numberOfUndos - 1]->inverseOperation);
		addNewRedoOperation(newOperation, controller->undoController);
		//addNewRedoOperation(controller->undoController->undoList[numberOfUndos - 1], controller->undoController);
		controller->undoController->lengthOfUndoList--;
	}
}

void redoOperation(char** finalList, SubstancesController *controller) {
	if (controller->undoController->lengthOfRedoList == 0)
		strcpy(finalList, "No more possible redos!");
	else {
		int numberOfRedos = controller->undoController->lengthOfRedoList;
		TElem* oldSubstance = controller->undoController->redoList[numberOfRedos - 1]->oldSubstance;
		controller->undoController->redoList[numberOfRedos - 1]->directOperation(oldSubstance, finalList, controller->substancesRepo);
	
		int undoLength = controller->undoController->lengthOfUndoList;
		addNewUndoOperation(controller->undoController->undoList[numberOfRedos - 1], controller->undoController);
		controller->undoController->lengthOfRedoList--;
	}
}