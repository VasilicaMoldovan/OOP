#pragma once
#include "domain.h"
#include <stdexcept>

template <typename T>

class DynamicVector {
private:
	T *vectorOfTasks;
	int capacityOfVector;
	int numberOfElements;
public:
	DynamicVector();
	DynamicVector(const DynamicVector& vector);
	DynamicVector& operator=(const DynamicVector& vector);
	T& operator[](int position);
	void addElement(T element);
	void deleteElement(T element);
	void updateElement(T element);
	int existingElement(T element);
	int getNumberOfElements();
	T* getAllElems() const;
	T getElementFromPosition(int position);
	~DynamicVector();
};

template <typename T>
DynamicVector<T>::DynamicVector() {
	this->capacityOfVector = 200;
	this->numberOfElements = 0;
	this->vectorOfTasks = new T[this->capacityOfVector];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& vector) {
	this->numberOfElements = vector.numberOfElements;
	this->capacityOfVector = vector.capacityOfVector;
	this->vectorOfTasks = new T[this->capacityOfVector];

	for (int index = 0; index < this->numberOfElements; index++)
		this->vectorOfTasks[index] = vector.vectorOfTasks[index];
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& vector) {
	if (this == &vector)
		return *this;

	this->numberOfElements = vector.numberOfElements;
	this->capacityOfVector = vector.capacityOfVector;

	delete[] this->vectorOfTasks;
	this->vectorOfTasks = new T[this->capacityOfVector];
	for (int index = 0; index < this->numberOfElements; index++)
		this->vectorOfTasks[index] = vector.vectorOfTasks[index];

	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int position) {
	return this->vectorOfTasks[position];
}

template <typename T>
void DynamicVector<T>::addElement(T element) {
	int elementIndex = existingElement(element);

	if (elementIndex != -1)
		throw std::invalid_argument("The task already exists!");
	else
	{
		if (this->numberOfElements == this->capacityOfVector) {
			this->capacityOfVector *= 1.5;
			T *auxiliaryVector = new T[this->capacityOfVector];
			for (int index = 0; index < this->numberOfElements; index++)
				auxiliaryVector[index] = this->vectorOfTasks[index];

			delete[] this->vectorOfTasks;
			this->vectorOfTasks = auxiliaryVector;
		}
		this->vectorOfTasks[this->numberOfElements] = element;
		this->numberOfElements++;
	}
}

template <typename T>
void DynamicVector<T>::deleteElement(T element) {
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

template <typename T>
int DynamicVector<T>::existingElement(T element) {
	for (int index = 0; index < this->numberOfElements; index++) {
		if (strcmp(this->vectorOfTasks[index].getType(), element.getType()) == 0)
			return index;
	}
	return -1;
}

template <typename T>
int DynamicVector<T>::getNumberOfElements() {
	return this->numberOfElements;
}

template <typename T>
T* DynamicVector<T>::getAllElems() const {
	return this->vectorOfTasks;
}

template <typename T>
T DynamicVector<T>::getElementFromPosition(int position) {
	return this->vectorOfTasks[position];
}

template <typename T>
DynamicVector<T>::~DynamicVector() {
	delete[] this->vectorOfTasks;
}