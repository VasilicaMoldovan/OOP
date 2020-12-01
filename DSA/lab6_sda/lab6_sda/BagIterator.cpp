#include "BagIterator.h"
#include "Bag.h"
#include <stdexcept>


BagIterator::BagIterator(const Bag& c) : bag(c){
	//The complexity is theta(m)
	this->currentPos = 0;
	this->currentFreq = 0;
	this->orderedElems = new TPair[this->bag.m];
	int j = 0;
	for (int i = 0; i < this->bag.m; i++)
	{
		if (!(this->bag.T[i].first == -1 && this->bag.T[i].second == -1))
			this->orderedElems[j++] = std::make_pair(this->bag.T[i].first, this->bag.T[i].second);
	}
}

void BagIterator::first() {
	//The complexity is theta(1)
	this->currentPos = 0;
	this->currentFreq = 0;
	this->nrElems = 0;
}

void BagIterator::next() {
	//The complexity is theta(1)
	if (this->valid() == false)
		throw std::invalid_argument("invalid position");
	else
	{
		if (this->currentFreq < this->orderedElems[this->currentPos].second - 1)
			this->currentFreq++;
		else
		{
			this->currentFreq = 0;
			this->currentPos++;
		}
		this->nrElems++;
	}
}

bool BagIterator::valid() const {
	//The complexity is theta(1)
	if (this->bag.nr == 0 || this->currentPos >= this->bag.nr || this->nrElems >= this->bag.nr)
		return false;
	return true;
}

TElem BagIterator::getCurrent() const {
	//The complexity is theta(1)
	if (this->valid() == false)
		throw std::invalid_argument("invalid position");
	else
		return this->orderedElems[this->currentPos].first;
}