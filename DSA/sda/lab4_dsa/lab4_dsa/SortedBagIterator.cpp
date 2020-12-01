#include "SortedBagIterator.h"
#include "SortedBag.h"
#include  <stdexcept>

SortedBagIterator::SortedBagIterator(const SortedBag& c): list(c) {
	//this->current = this->list.cap;
	this->current = this->list.head;
}

TElem SortedBagIterator::getCurrent() const {
	if (valid() == false)
		throw std::invalid_argument("invalid iterator");
	else {
		//TElem e;
		return this->list.nodes[this->current].info;
	}
}

void SortedBagIterator::next() {
	if (valid() == false)
		throw std::invalid_argument("invalid iterator");
	else
		this->current = this->list.nodes[this->current].next;
}

bool SortedBagIterator::valid() const {
	if (this->current == -1)
		return false;
	return true;
}

void SortedBagIterator::first() {
	this->current = this->list.head;
}