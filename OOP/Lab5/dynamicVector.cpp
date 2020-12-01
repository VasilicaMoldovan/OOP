#include "dynamicVector.h"
#include <stdexcept>

DynamicVector::DynamicVector() {
	this->capacityOfVector = 200;
	this->numberOfElements = 0;
	this->vectorOfTasks = new TElem[this->capacityOfVector];
}

DynamicVector::DynamicVector(const DynamicVector& vector) {
	this->numberOfElements = vector.numberOfElements;
	this->capacityOfVector = vector.capacityOfVector;
	this->vectorOfTasks = new TElem[this->capacityOfVector];

	for (int index = 0; index < this->numberOfElements; index++)
		this->vectorOfTasks[index] = vector.vectorOfTasks[index];
}

DynamicVector& DynamicVector::operator=(const DynamicVector& vector) {
	if (this == &vector)
		return *this;

	this->numberOfElements = vector.numberOfElements;
	this->capacityOfVector = vector.capacityOfVector;

	delete[] this->vectorOfTasks;
	this->vectorOfTasks = new TElem[this->capacityOfVector];
	for (int index = 0; index < this->numberOfElements; index++)
		this->vectorOfTasks[index] = vector.vectorOfTasks[index];

	return *this;
}


void DynamicVector::addElement(TElem element) {
	int elementIndex = existingElement(element);

	if (elementIndex != -1 )
		throw std::invalid_argument("The task already exists!");
	else 
	{
		if (this->numberOfElements == this->capacityOfVector) {
			this->capacityOfVector *= 1.5;
			TElem *auxiliaryVector = new TElem[this->capacityOfVector];
			for (int index = 0; index < this->numberOfElements; index++)
				auxiliaryVector[index] = this->vectorOfTasks[index];

			delete[] this->vectorOfTasks;
			this->vectorOfTasks = auxiliaryVector;
		}
		this->vectorOfTasks[this->numberOfElements] = element;
		this->numberOfElements++;
	}
}

void DynamicVector::deleteElement(TElem element) {
	int elementIndex = existingElement(element);
	
	if (elementIndex == -1)
		throw std::invalid_argument("The required task does not exist!");
	else {
		for (int index = elementIndex; index < this->numberOfElements - 1; index++) {
			this->vectorOfTasks[index] = this->vectorOfTasks[index + 1];
		}
		this->numberOfElements--;
	}
}

void DynamicVector::updateElement(TElem element) {
	int elementIndex = existingElement(element);
	
	if (elementIndex == -1)
		throw std::invalid_argument("The required task does not exist!");
	else {
		this->vectorOfTasks[elementIndex].setDate(element.getDate());
		this->vectorOfTasks[elementIndex].setMirrorImage(element.getMirrorImage());
		this->vectorOfTasks[elementIndex].setNumberOfRepetitions(element.getNumberOfRepetitions());
		this->vectorOfTasks[elementIndex].setTitle(element.getTitle());
		this->vectorOfTasks[elementIndex].setType(element.getType());
	}
}

int DynamicVector::existingElement(TElem element) {
	for (int index = 0; index < this->numberOfElements; index++) {
		if (strcmp(this->vectorOfTasks[index].getTitle(), element.getTitle()) == 0)
			return index;
	}
	return -1;
}

int DynamicVector::getNumberOfElements() {
	return this->numberOfElements;
}

TElem* DynamicVector::getAllElems() const {
	return this->vectorOfTasks;
}

DynamicVector::~DynamicVector() {
	delete[] this->vectorOfTasks;
}