#include "multiMap.h"
#include "multiMapIterator.h"

TKey MultiMap::minKey() const {
	// The complexity is O(n)
	if (this->head == NULL) {
		return NULL_TKEY;
	}
	else {
		Node *node = this->head;
		int cnt = 0;
		int min = 0;
		while (node->next != NULL) {
			if (cnt == 0) {
				min = node->info.first;
				cnt++;
			}
			else {
				if (min > node->info.first)
					min = node->info.first;
			}
			node = node->next;
		}
		return min;
	}
}

MultiMap::MultiMap() {
	// The complexity is (1)
	this->head = NULL;
	this->tail = NULL;
	this->sizeOfMap = 0;
}

void MultiMap::add(TKey c, TValue v) {
	// The complexity is (1)
	Node *node = new(Node);
	if (this->head == NULL) {
		this->head = node;
		this->head->info.second.push(v);
		TElement value = std::make_pair(c, this->head->info.second);
		this->head->info = value;
		this->tail = this->head;
		this->tail->next = NULL;
		this->sizeOfMap++;
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
		this->sizeOfMap++;
		if (!cnt) {
			node = new(Node);
			node->previous = this->tail;
			this->tail->next = node;
			this->tail = node;
			this->tail->info.second.push(v);
			TElement value = std::make_pair(c, this->tail->info.second);
			this->tail->info = value;
			this->tail->next = NULL;
			//this->sizeOfMap++;
		}
	}
}
bool MultiMap::remove(TKey c, TValue v) {
	//The complexity is (1)
	Node *currentNode = this->head;
	bool deleted = false;
	while (currentNode != NULL && currentNode->info.first != c) {
		currentNode = currentNode->next;
	}
	if (currentNode != NULL) {
		if (currentNode->info.second.existingValue(v) == true) {
			if (currentNode->info.second.getLength() > 1) {
				deleted = currentNode->info.second.deleteElement(v);
			}
			else {
				if (currentNode == this->head) {
					this->head = this->head->next;
					deleted = true;
					if (this->head != NULL)
						this->head->previous = NULL;
				}
				else {
					if (currentNode == this->tail) {
						this->tail = this->tail->previous;
						deleted = true;
						if (this->tail != NULL)
							this->tail->next = NULL;
					}
					else {
						currentNode->next->previous = currentNode->previous;
						currentNode->previous->next = currentNode->next;
						deleted = true;
					}
				}
			}
			this->sizeOfMap--;
		}
	}
	return deleted;
}

/*
bool MultiMap::remove(TKey c, TValue v) {
	bool cnt = false;
	Node *node = new(Node);
	node = this->head;
	while (node != NULL && !cnt) {
		if (node->info.first == c && node->info.second.existingValue(v) == true) {
			if (node->info.second.getLength() == 1) {
				if (node == this->head) {
					this->head->previous = NULL;
					this->head = this->head->next;
				}
				else {
					if (node == this->tail) {
						this->tail->next = NULL;
						this->tail = this->tail->previous;
					}
					else {
						node->next->previous = node->previous;
						node->previous->next = node->next;
					}
				}
				this->sizeOfMap--;
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
*/
vector<TValue> MultiMap::search(TKey c) const {
	// The complexity is O(n + m)
	vector<TValue> vect;
	Node *node = this->head;
	DLLNode *aux;
	while (node != NULL) {
		if (node->info.first == c) {
			//vect = vector<TValue>(node->info.second.getLength() + 1);
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
	//The complexity is (1)
	return this->sizeOfMap;
	/*
	int count = 0;
	Node* node = this->head;
	int length = 0;
	while (node != NULL) {
		count += node->info.second.getLength();
		node = node->next;
		length++;
	}
	return count;*/
}

bool MultiMap::isEmpty() const {
	if (this->sizeOfMap == 0)
		return true;
	return false;
}

int MultiMap::getDllLength(int position) const{
	//The complexity is O(n)
	Node* node = this->head;
	int count = 0;
	int length = 0;
	while (count < position && node != NULL) {
		node = node->next;
		count++;
	}
	if (count == position) {
		length = node->info.second.getLength();
	}
	return length;
}

TElem MultiMap::giveElement(int position1, int position2) const {
	//The complexity is O(n)
	Node* node = this->head;
	TElem elem;
	int i = 0;
	while (i < position1 && node != NULL) {
		i++;
		node = node->next;
	}
	return std::make_pair(node->info.first, node->info.second.getFromPosition(position2));
	//return node->info.second->head->info;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

