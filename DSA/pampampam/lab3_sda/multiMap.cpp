#include "multiMap.h"
#include "multiMapIterator.h"

MultiMap::MultiMap() {
	this->head = NULL;
	this->tail = NULL;
	this->sizeOfMap = 0;
}

void MultiMap::add(TKey c, TValue v) {
	Node *node = new(Node);
	if (this->head == NULL) {
		this->head = node;
		this->head->info.second.push(v);
		TElement value = std::make_pair(c, this->head->info.second);
		this->head->info = value;
		this->tail = this->head;
		this->tail->next = NULL;
		this->size++;
	}
	else {
		bool cnt = false;
		node = this->head;
		while (node != NULL) {
			if (node->info.first == c) {
				node->info.second.push(v);
				cnt = true;
			}
			node = node->next;
		}
		if (!cnt) {
			node = new(Node);
			node->previous = this->tail;
			this->tail->next = node;
			this->tail = node;
			this->tail->info.second.push(v);
			TElement value = std::make_pair(c, this->head->info.second);
			this->tail->info = value;
			this->tail->next = NULL;
			this->size++;
		}
	}
}

bool MultiMap::remove(TKey c, TValue v) {
	bool cnt = false;
	Node *node = new(Node);
	node = this->head;
	while (node != NULL && !cnt) {
		if (node->info.first == c && node->info.second.existingValue(v) == true) {
			if (node->info.second.getLength() == 1) {
				node->previous->next = node->next;
				node->next->previous = node->previous;
			}
			else {
				node->info.second.deleteElement(v);
			}
			cnt = true;
		}
		node = node->next;
	}
	return cnt;
}

vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> vect;
	Node *node = this->head;
	DLLNode *aux;
	while (node != NULL) {
		if (node->info.first == c) {
			vect = vector<TValue>(node->info.second.getLength() + 1);
			aux = node->info.second.getHead();
			for (int i = 0; i < node->info.second.getLength(); i++) {
				vect.push_back(aux->info);
			}
			break;
		}
		node = node->next;
	}
	return vect;
}

int MultiMap::size() const {
	return this->sizeOfMap;
}

bool MultiMap::isEmpty() const {
	if (this->sizeOfMap == 0)
		return true;
	return false;
}

TElement MultiMap::giveElement(int position) const {
	Node* node = this->head;
	int i = 0;
	while (i < position && node != NULL) {
		i++;
		node = node->next;
	}
	return node->info;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}



/*
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
*/