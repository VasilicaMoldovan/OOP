#include "SortedBagIterator.h"
#include "SortedBag.h"
#include  <stdexcept>

SortedBagIterator::SortedBagIterator(const SortedBag& c): list(c) {
	//this->current = this->list.cap;
	this->current = this->list.head;
	this->currentFreq = 0;
}

TElem SortedBagIterator::getCurrent() const {
	if (valid() == false)
		throw std::invalid_argument("invalid iterator");
	else {
		return this->list.nodes[this->current].info;
	}
}

void SortedBagIterator::next() {
	if (valid() == false)
		throw std::invalid_argument("invalid iterator");
	else {
		if (this->currentFreq <= this->list.nodes[this->current].next) {
			this->currentFreq += 1;
		}
		else {
			this->current = this->list.nodes[this->current].next;
			this->currentFreq = 0;
		}
	}
}

bool SortedBagIterator::valid() const {
	if (this->current == -1)
		return false;
	return true;
}

void SortedBagIterator::first() {
	this->current = this->list.head;
}