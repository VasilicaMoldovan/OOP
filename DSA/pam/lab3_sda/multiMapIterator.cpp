#include "multiMapIterator.h"
#include "multiMap.h"
#include <stdexcept>

MultiMapIterator::MultiMapIterator(const MultiMap& c): con(c) {
	this->current = 0;
	this->currentValues = 0;
	this->numberOfPairs = 0;
}

void MultiMapIterator::first() {
	this->current = 0;
	this->currentValues = 0;
	this->numberOfPairs = 0;
}

void MultiMapIterator::next() {
	if (this->valid() == false)
		throw std::invalid_argument("invalid position");
	else {
		if (this->currentValues < this->con.getDllLength(this->current) - 1)
			this->currentValues++;
		else {
			this->current++;
			this->currentValues = 0;
		}
		this->numberOfPairs++;
	}
}

bool MultiMapIterator::valid() const {
	return this->numberOfPairs < this->con.size();
}

TElem MultiMapIterator::getCurrent() const{
	if (this->current == this->con.size())
		throw std::invalid_argument("invalid iterator");
	else
		return this->con.giveElement(this->current, this->currentValues);
}