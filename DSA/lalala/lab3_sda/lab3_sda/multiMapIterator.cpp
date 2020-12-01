#include "multiMapIterator.h"
#include "multiMap.h"
#include <stdexcept>

MultiMapIterator::MultiMapIterator(const MultiMap& c): con(c) {
	this->current = 0;
}

void MultiMapIterator::first() {
	this->current = 0;
}

void MultiMapIterator::next() {
	if (this->valid() == true) {
		if (this->current == this->con.size()) {
			throw std::invalid_argument("invalid position");
		}
		else
			this->current++;
	}
}

bool MultiMapIterator::valid() const {
	return this->current < this->con.size();
}

TElem MultiMapIterator::getCurrent() const{
	if (this->current == this->con.size())
		throw std::invalid_argument("invalid iterator");
	else
		return this->con.giveElement(this->current);
}