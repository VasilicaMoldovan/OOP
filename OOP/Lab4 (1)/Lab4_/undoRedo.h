#pragma once
#include "Domain.h"
#include "Repository.h"
typedef Substance TElem;
//typedef (*operation)(TElem*, char*);
typedef (*operation)(TElem*, char**, SubstanceRepository*);

typedef struct {
	TElem *oldSubstance;
	TElem *newSubstance;
	//char* directOperation;
	//char* inverseOperation;
	operation directOperation;
	operation inverseOperation;

}UndoOperation;

typedef struct {
	int capacityOfUndoList;
	int lengthOfUndoList;
	int lengthOfRedoList;
	UndoOperation** undoList;
	UndoOperation** redoList;
}UndoRedo;

void addNewUndoOperation(UndoOperation* operation, UndoRedo* undoOperations);
void addNewRedoOperation(UndoOperation* operation, UndoRedo* undoOperations);
UndoOperation* createUndoOperation(TElem* oldSubstance, TElem* newSubstance, operation directOperation, operation inverseOperation);
UndoRedo* createUndoRedo();
