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