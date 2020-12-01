#include "undoRedo.h"

UndoOperation* createUndoOperation(TElem* oldSubstance, TElem* newSubstance, operation directOperation, operation* inverseOperation) {
	UndoOperation *newOperation;
	newOperation = (UndoOperation*)malloc(sizeof(UndoOperation));
	newOperation->oldSubstance = oldSubstance;
	newOperation->newSubstance = newSubstance;
	newOperation->directOperation = (operation)malloc(sizeof(operation*));
	newOperation->inverseOperation = (operation)malloc(sizeof(operation*));

	newOperation->directOperation = directOperation;
	newOperation->inverseOperation = inverseOperation;

	return newOperation;
}

UndoRedo* createUndoRedo(){
	UndoRedo* undoRedoList = (UndoRedo*)malloc(sizeof(UndoRedo));
	undoRedoList->lengthOfUndoList = 0;
	undoRedoList->lengthOfRedoList = 0;
	undoRedoList->capacityOfUndoList = 200;
	undoRedoList->undoList = (UndoOperation**)malloc(undoRedoList->capacityOfUndoList * sizeof(UndoOperation*));
	undoRedoList->redoList = (UndoOperation**)malloc(undoRedoList->capacityOfUndoList * sizeof(UndoOperation*));

	return undoRedoList;
}

void addNewUndoOperation(UndoOperation* operation, UndoRedo* undoOperations) {
	if (undoOperations->capacityOfUndoList == undoOperations->lengthOfUndoList) {
		undoOperations->capacityOfUndoList *= 1.5;
		undoOperations = (UndoRedo**)realloc(undoOperations->undoList, sizeof(UndoOperation*) * undoOperations->capacityOfUndoList);
	}
	undoOperations->undoList[undoOperations->lengthOfUndoList] = operation;
	undoOperations->lengthOfUndoList++;
}

void addNewRedoOperation(UndoOperation* operation, UndoRedo* undoOperations) {
	if (undoOperations->capacityOfUndoList == undoOperations->lengthOfRedoList) {
		undoOperations->capacityOfUndoList *= 1.5;
		undoOperations = (UndoRedo**)realloc(undoOperations->undoList, sizeof(UndoOperation*) * undoOperations->capacityOfUndoList);
	}
	undoOperations->redoList[undoOperations->lengthOfRedoList] = operation;
	undoOperations->lengthOfRedoList++;
}

void deallocateUndoOperation(UndoOperation* newOperation) {
	if (newOperation == NULL)
		return;

	free(newOperation->directOperation);
	free(newOperation->inverseOperation);
	free(newOperation);
}

void deallocateUndoRedo(UndoRedo* undoRedo) {
	if (undoRedo == NULL)
		return;
	
	///*for (int index = 0; index < undoRedo->lengthOfUndoList; index++) {
		deallocateUndoOperation(undoRedo->undoList[index]->directOperation);
		deallocateUndoOperation(undoRedo->undoList[index]->inverseOperation);
	}*/
	free(undoRedo->undoList);
	undoRedo->undoList = NULL;
	/*for (int index = 0; index < undoRedo->lengthOfRedoList; index++) {
		deallocateUndoOperation(undoRedo->redoList[index]->directOperation);
		deallocateUndoOperation(undoRedo->redoList[index]->inverseOperation);
	}*/
	free(undoRedo->redoList);
	undoRedo->redoList = NULL;
	free(undoRedo);
	undoRedo = NULL;
}
