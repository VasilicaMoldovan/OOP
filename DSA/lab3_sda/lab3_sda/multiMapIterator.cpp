#include "multiMapIterator.h"
#include "multiMap.h"
#include <stdexcept>
using namespace std;

MultiMapIterator::MultiMapIterator(const MultiMap& c): con(c) {
	this->current = this->con.head;
	if (this->current != NULL)
		this->currentValues = this->con.head->info.second.getHead();
	else
		this->currentValues = NULL;
	this->numberOfPairs = 0;
}

void MultiMapIterator::first() {
	this->current = this->con.head;
	this->currentValues = this->con.head->info.second.getHead();
	this->numberOfPairs = 0;
}

void MultiMapIterator::next() {
	if (this->valid() == false)
		throw std::invalid_argument("invalid position");
	else {
		if (this->currentValues->next != NULL)
			this->currentValues = this->currentValues->next;
		//if (this->currentValues < this->con.getDllLength(this->current) - 1)
			//this->currentValues++;
		else {
			//this->current++;
			//this->currentValues = 0;
			this->current = this->current->next;
			if (this->current != NULL)
				this->currentValues = this->current->info.second.getHead();
		}
		this->numberOfPairs++;
	}
}

bool MultiMapIterator::valid() const {
	//return this->current != NULL;
	return this->numberOfPairs < this->con.size() - 1;
}

TElem MultiMapIterator::getCurrent() const{
	if (this->current == NULL)
		//if (this->current == this->con.size())
		throw std::invalid_argument("invalid iterator");
	else
		return std::make_pair(this->current->info.first, this->currentValues->info);
		//return this->con.giveElement(this->current, this->currentValues);
}