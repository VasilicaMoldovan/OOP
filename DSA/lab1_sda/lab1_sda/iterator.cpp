#include "iterator.h"
#include "sortedBag.h"
#include <stdexcept>

SortedBagIterator::SortedBagIterator(const SortedBag& c): con(c) {
	//The total complexity is O(1)
	this->current = 0;
	this->frequencyCurrent = 0;
}

void SortedBagIterator::first() {
	//The total complexity is O(1)
	this->current = 0;
	this->frequencyCurrent = 0;
}

void SortedBagIterator::next() {
	//The total complexity is O(1)
	if (this->valid() == true) {
		if (this->frequencyCurrent == this->con.frequency[this->current] - 1) {
			this->current++;
			this->frequencyCurrent = -1;
		}
		this->frequencyCurrent++;
	}
	else
		throw std::invalid_argument("invalid position");
}

bool SortedBagIterator::valid() const {
	//The total complexity is O(1)
	return this->current < this->con.lengthOfVector;
		
}

TElem SortedBagIterator::getCurrent() const {
	//The total complexity is O(1)
	if (this->current == this->con.lengthOfVector)
		throw std::invalid_argument("invalid iterator");
	return this->con.elements[this->current];
}