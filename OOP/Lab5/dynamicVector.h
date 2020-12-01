#pragma once
#include "domain.h"

typedef Refurbishment TElem;

class DynamicVector {
private:
	TElem *vectorOfTasks;
	int capacityOfVector;
	int numberOfElements;
public:
	DynamicVector();
	DynamicVector(const DynamicVector& vector);
	DynamicVector& operator=(const DynamicVector& vector);
	void addElement(TElem element);
	void deleteElement(TElem element);
	void updateElement(TElem element);
	int existingElement(TElem element);
	int getNumberOfElements();
	TElem* getAllElems() const;
	~DynamicVector();
};