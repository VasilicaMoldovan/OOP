#include "sortedBag.h"
#include "iterator.h"
#include <iostream>

int SortedBag::elementsWithThisFrequency(int frequency) const {
	if (frequency <= 0)
		throw std::invalid_argument("invalid frequency");
	else {
		int count = 0;
		for (int i = 0; i < this->lengthOfVector; i++) {
			if (this->frequency[i] == frequency)
				count++;
		}
		return count;
	}
}

SortedBag::SortedBag(Relation r) {
	this->lengthOfVector = 0;
	this->capacity = 100;
	this->elements = new TComp[this->capacity];
	this->frequency = new int[this->capacity];
	this->newRelation = r;
}

SortedBag::SortedBag(const SortedBag &bag) {
	this->lengthOfVector = bag.lengthOfVector;
	this->capacity = bag.capacity;
	this->elements = new TComp[this->capacity];
	for (int i = 0; i < this->lengthOfVector; i++) {
		this->elements[i] = bag.elements[i];
		this->frequency[i] = bag.frequency[i];
	}
}

void SortedBag::add(TComp e) {
	// The overall complexity is O(n)
	if (this->lengthOfVector == this->capacity)
		this->resize();

	int index = -1;
	for (int i = 0; i < this->lengthOfVector; i++) {
		if (this->elements[i] == e) {
			index = i;
			break;
		}
	}
	if (index != -1)
		this->frequency[index]++;
	else {
		int i = 0;
		while (i < this->lengthOfVector && this->newRelation(this->elements[i], e)) {
			i++;
		}
		if (i == this->lengthOfVector) {
			this->elements[i] = e;
			this->frequency[i] = 1;
		}
		else {
			for (int j = this->lengthOfVector; j > i; j--) {
				this->elements[j] = this->elements[j - 1];
				this->frequency[j] = this->frequency[j - 1];
			}
			this->elements[i] = e;
			this->frequency[i] = 1;
		}
		this->lengthOfVector++;
	}
}

bool SortedBag::remove(TComp e) {
	//The total complexity is O(n)
	bool existing = false;

	for (int i = 0; i < this->lengthOfVector; i++) {
		if (this->elements[i] == e) {
			this->frequency[i]--;
			if (this->frequency[i] == 0) {
				if (i == this->lengthOfVector - 1)
					this->lengthOfVector--;
				else {
					for (int j = i; j < this->lengthOfVector - 1; j++) {
						this->elements[j] = this->elements[j + 1];
						this->frequency[j] = this->frequency[j + 1];
					}
					this->lengthOfVector--;
				}
			}
			existing = true;
			break;
		}
	}
	return existing;
}

bool SortedBag::search(TComp e) const {
	//The total complexity is O(n)
	bool existing = false;
	for (int i = 0; i < this->lengthOfVector; i++) {
		if (this->elements[i] == e) {
			existing = true;
			break;
		}
	}
	return existing;
}

int SortedBag::nrOccurrences(TComp e) const {
	//The total complexity is O(n)
	int numberOfOccurrences = 0;
	for (int i = 0; i < this->lengthOfVector; i++) {
		if (this->elements[i] == e) {
			numberOfOccurrences += this->frequency[i];
			break;
		}
	}
	return numberOfOccurrences;
}

int SortedBag::size() const {
	//The total complexity is theta(n)
	int size = 0;
	for (int i = 0; i < this->lengthOfVector; i++)
		size += this->frequency[i];

	return size;
}

SortedBagIterator SortedBag::iterator() const {
	//The total complexity is O(1)
	return SortedBagIterator(*this);
}

bool SortedBag::isEmpty() const {
	//The total complexity is O(1)
	if (this->lengthOfVector == 0)
		return true;
	return false;
}

SortedBag::~SortedBag() {
	delete[] this->elements;
	delete[] this->frequency;
}

void SortedBag::resize(double factor) {
	//The total complexity is O(n)
	this->capacity *= factor;

	TComp *aux = new TComp[this->capacity];
	TComp *secondAux = new TComp[this->capacity];
	for (int i = 0; i < this->lengthOfVector; i++) {
		aux[i] = this->elements[i];
		secondAux[i] = this->frequency[i];
	}

	delete[] this->elements;
	delete[] this->frequency;
	elements = aux;
	frequency = secondAux;
}