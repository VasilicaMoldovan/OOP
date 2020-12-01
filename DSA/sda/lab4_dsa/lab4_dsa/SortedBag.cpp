#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
using namespace std;

SortedBag::SortedBag(Relation r) {
	this->cap = 50000;
	this->nodes = new DLLANode[this->cap];
	this->head = -1;
	this->firstEmpty = 0;
	this->tail = -1;
	this->newRelation = r;
	for (int i = 0; i <= this->cap; i++) {
		this->nodes[i].next = i + 1;
		this->nodes[i].next = i - 1;
	}
	this->nodes[this->cap].next = -1;
	this->lengthOfVector = 0;
	this->tempLength = 0;
}

SortedBag::SortedBag(const SortedBag &bag) {
	this->cap = bag.cap;
	this->firstEmpty = bag.firstEmpty;
	this->head = bag.head;
	this->newRelation = bag.newRelation;
	this->nodes = new DLLANode[this->cap];
	for (int i = 0; i < this->cap; i++) {
		this->nodes[i] = bag.nodes[i];
	}
	this->tail = bag.tail;
}

int SortedBag::allocate() {
	int newElem = this->firstEmpty;
	if (this->firstEmpty >= this->cap)
		newElem = -1;
	if (newElem != -1) {
		this->nodes[this->firstEmpty].next = this->firstEmpty + 1;
		this->firstEmpty = this->nodes[this->firstEmpty].next;
		this->nodes[this->firstEmpty].prev = -1;
		this->nodes[newElem].next = -1;
		this->nodes[newElem].prev = -1;
	}
	return newElem;
}

void SortedBag::free(int position) {
	this->nodes[position].next = this->firstEmpty;
	this->nodes[position].prev = -1;
	this->nodes[this->firstEmpty].prev = position;
	this->firstEmpty = position;
}

void SortedBag::insertAtPosition(TComp elem, int position) {
	int newElem = this->allocate();
	if (newElem == -1) {
		this->resize();
		newElem = this->allocate();
	}
	this->nodes[newElem].info = elem;
	this->nodes[newElem].freq = 1;
	if (position == 0) {
		if (this->head == -1) {
			this->head = newElem;
			this->tail = newElem;
		}
		else {
			this->nodes[newElem].next = this->head;
			this->nodes[this->head].prev = newElem;
			this->head = newElem;
		}
	}
	else {
		int nodeC = this->head;
		int pozC = 0;
		while (nodeC != -1 && pozC < position - 1) {
			nodeC = this->nodes[nodeC].next;
			pozC += 1;
		}
		if (nodeC != -1) {
			int nodeNext = this->nodes[nodeC].next;
			this->nodes[newElem].next = nodeNext;
			this->nodes[newElem].prev = nodeC;
			this->nodes[nodeC].next = newElem;
			if (nodeNext == -1) {
				this->tail = newElem;
				this->nodes[this->tail].next = -1;
			}
			else {
				this->nodes[nodeNext].prev = newElem;
			}
		}
	}
}

void SortedBag::resize(double factor) {
	//The total complexity is O(n)
	int length = this->cap;
	this->cap *= factor;

	DLLANode *aux = new DLLANode[this->cap];
	int node = this->head;
	while (node != -1) {
		aux[node] = this->nodes[node];
		node = this->nodes[node].next;
	}
	//for (int i = 0; i < length; i++) {
	//	aux[i] = this->nodes[i];
	//}

	delete[] this->nodes;
	nodes = aux;
}

SortedBagIterator SortedBag::iterator() const {
	//The total complexity is O(1)
	return SortedBagIterator(*this);
}


bool SortedBag::search(TComp e) const {
	int current = this->head;
	int length = 0;
	while (current != -1 && this->nodes[current].info != e && length < this->lengthOfVector) {
		current = this->nodes[current].next;
		length++;
	}
	if (current == -1)
		return false;
	if (length == this->lengthOfVector)
		return false;
	return true;
}

void SortedBag::add(TComp e) {
	// The overall complexity is O(n)
	if (this->lengthOfVector == this->cap)
		this->resize();

	int index = this->head;
	int cnt = 0;
	while (index != -1 && this->newRelation(this->nodes[index].info, e)) {
		if (this->nodes[index].info == e)
			break;
		index = this->nodes[index].next;
	}

	if (index != -1) {
		if (this->nodes[index].info == e) {
			this->nodes[index].freq++;
			this->lengthOfVector++;
			this->tempLength++;
		}
		else {
			if (index == this->head) {
				this->nodes[this->firstEmpty].info = e;
				this->nodes[this->firstEmpty].freq = 1;
				this->nodes[this->firstEmpty].prev = -1;
				this->nodes[this->firstEmpty].next = this->head;
				this->nodes[this->head].prev = this->firstEmpty;
				this->head = this->firstEmpty;
				this->firstEmpty = this->tempLength + 1;
				//this->firstEmpty = this->nodes[this->firstEmpty].next;
			}
			else {
					this->nodes[this->firstEmpty].info = e;
					this->nodes[this->firstEmpty].freq = 1;
					this->nodes[this->firstEmpty].next = index;
					this->nodes[this->firstEmpty].prev = this->nodes[index].prev;
					this->nodes[this->nodes[index].prev].next = this->firstEmpty;
					this->nodes[index].prev = this->firstEmpty;
					this->firstEmpty = this->tempLength + 1;
					//this->firstEmpty = this->nodes[this->firstEmpty].next;
			}
			this->lengthOfVector++;
			this->tempLength++;
		}
	}
	else {
		if (this->head == -1) {
			this->nodes[0].prev = -1;
			this->nodes[0].next = -1;
			this->nodes[0].info = e;
			this->nodes[0].freq = 1;
			this->head = 0;
			this->tail = 0;
			this->firstEmpty = 1;
		}
		else {
			this->nodes[this->firstEmpty].info = e;
			this->nodes[this->firstEmpty].freq = 1;
			this->nodes[this->firstEmpty].next = -1;
			this->nodes[this->firstEmpty].prev = this->tail;
			this->nodes[this->tail].next = this->firstEmpty;
			this->tail = this->firstEmpty;
			this->firstEmpty = this->tempLength + 1;
			//this->firstEmpty = this->nodes[this->firstEmpty].next;
		}
		this->lengthOfVector++;
		this->tempLength++;
	}
}
bool SortedBag::remove(TComp e) {
	bool deleted = false;
	int node = this->head;

	while (node != -1 && this->newRelation(this->nodes[node].info, e)) {
		if (this->nodes[node].info == e)
			break;
		node = this->nodes[node].next;
	}
	if (node != -1 && this->nodes[node].info == e) {
		this->nodes[node].freq--;
		if (this->nodes[node].freq == 0) {
			if (node == this->head) {
				this->nodes[this->nodes[this->head].next].prev = -1;
				this->head = this->nodes[this->head].next;
				//this->nodes[this->firstEmpty].next = node;
				this->firstEmpty = node;
			}
			else {
				if (node == this->tail) {
					this->nodes[this->nodes[this->tail].prev].next = -1;
					this->tail = this->nodes[this->tail].prev;
					//this->nodes[this->firstEmpty].next = node;
					this->firstEmpty = node;
				}
				else {
					this->nodes[this->nodes[node].prev].next = this->nodes[node].next;
					this->nodes[this->nodes[node].next].prev = this->nodes[node].prev;
					//this->nodes[this->firstEmpty].next = node;
					this->firstEmpty = node;
				}
			}
		}
		deleted = true;
	}
	if (deleted == true)
		this->lengthOfVector--;
	return deleted;
}

/*
bool SortedBag::remove(TComp e) {
	bool deleted = false;
	int nodeC = this->head;
	int prevNode = -1;
	while (nodeC != -1 && this->nodes[nodeC].info != e) {
		prevNode = nodeC;
		nodeC = this->nodes[nodeC].next;
	}
	if (nodeC != -1) {
		if (nodeC == this->head) {
			this->head = this->nodes[this->head].next;
		}
		else {
			this->nodes[prevNode].next = this->nodes[nodeC].next;
			this->nodes[nodeC].next = this->firstEmpty;
			this->firstEmpty = nodeC;
		}
		deleted = true;
	}
	return deleted;
}
*/
/*
bool SortedBag::remove(TComp e) {
	bool deleted = false;
	if (search(e) == false)
		return false;
	int node = this->head;
	while (node != -1 && this->nodes[node].info != e) {
		node = this->nodes[node].next;
	}
	this->nodes[node].freq--;
	if (this->nodes[node].freq == 0) {
		if (node == this->head) {
			this->head = this->nodes[this->head].next;
			this->nodes[this->head].prev = -1;
			this->lengthOfVector--;
		}
		else {
			if (node == this->tail) {
				this->tail = this->nodes[this->tail].prev;
				this->nodes[this->tail].next = -1;
				this->lengthOfVector--;
			}
			else {
				this->nodes[this->nodes[node].prev].next = this->nodes[node].next;
				this->nodes[this->nodes[node].next].prev = this->nodes[node].prev;
				this->lengthOfVector--;
			}
		}
	}
	return true;
}
*/
/*
void SortedBag::add(TComp e) {
	int node = this->head;
	if (isEmpty()) {
		this->head = 0;
		this->tail = 0;
		this->nodes[this->head].freq = 1;
		this->nodes[this->head].info = e;
		this->firstEmpty++;
		this->nodes[this->head].next = this->firstEmpty;
		this->nodes[this->head].prev = -1;
	}
	else {
		while (node != this->tail && this->newRelation(this->nodes[node].info, e)) {
			if (this->nodes[node].info == e)
				break;
			node = this->nodes[node].next;
		}

		if (this->nodes[node].info == e) {
			this->nodes[node].freq++;
		}
		else {
			if (this->newRelation(this->nodes[node].info, e)) {
				insertAtPosition(e, this->firstEmpty);
				//this->nodes[node].next = this->firstEmpty;
				//this->nodes[this->firstEmpty].prev = node;
			}
			else {
				insertAtPosition(e, node);
			}
		}
	}
	this->nodes[this->tail].next = -1;
}
*/
/*
bool SortedBag::remove(TComp e) {
	bool deleted = false;
	if (search(e) == false)
		return false;
	int node = this->head;
	while (node != -1 && this->nodes[node].info != e) {
		node = this->nodes[node].next;
	}
	this->nodes[node].freq--;
	if (this->nodes[node].freq == 0) {
		if (node == this->tail) {
			int index = this->nodes[node].prev;
			this->nodes[index].next = -1;
			this->tail = this->nodes[node].prev;
		}
		else {
			int index = this->nodes[node].prev;
			this->nodes[index].next = this->nodes[node].next;
			int index2 = this->nodes[node].next;
			this->nodes[index2].prev = index;
		}
	}
	this->nodes[this->tail].next = -1;
	return true;
}
*/
int SortedBag::nrOccurrences(TComp e) const {
	if (search(e) == false)
		return 0;
	int newNode = this->head;
	while (newNode != -1 && this->nodes[newNode].info != e) {
		newNode = this->nodes[newNode].next;
	}
	return this->nodes[newNode].freq;
}

int SortedBag::size() const {
	/*
	int count = 0;
	int node = this->head;
	while (node != -1) {
		count += this->nodes[node].freq;
		node = this->nodes[node].next;
	}
	return count;*/
	return this->lengthOfVector;
}

bool SortedBag::isEmpty() const {
	if (this->head == -1)
		return true;
	return false;
}

SortedBag::~SortedBag() {
	delete[] this->nodes;
}