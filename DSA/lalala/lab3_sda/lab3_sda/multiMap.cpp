#include "multiMap.h"
#include "multiMapIterator.h"

MultiMap::MultiMap() {
	
}

void MultiMap::add(TKey c, TValue v) {
	TElem value = std::make_pair(c, v);
	this->map->push(value);
}

bool MultiMap::remove(TKey c, TValue v) {
	TElem value = std::make_pair(c, v);
	return this->map->deleteElement(value);
}

vector<TValue> MultiMap::search(TKey c) const {
	return this->map->searchElement(c);
}

int MultiMap::size() const {
	return this->map->getLength();
}

bool MultiMap::isEmpty() const {
	if (this->map->getLength() == 0)
		return true;
	return false;
}

TElem MultiMap::giveElement(int position) const{
	return this->map->getFromPosition(position);
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}
