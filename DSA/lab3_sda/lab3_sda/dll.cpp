#include "dll.h"

DLL::DLL() {
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

DLLNode* DLL::getHead() {
	return this->head;
}

DLLNode* DLL::getTail() {
	return this->tail;
}

int DLL::getLength() {
	return this->length;
}

void DLL::push(TValue info) {
	DLLNode *node = new(DLLNode);
	node->info = info;
	node->next = NULL;
	node->previous = NULL;

	if (this->head == NULL) {
		
		this->head = node;
		this->tail = this->head;
		this->tail->next = NULL;
		this->length++;
	}
	else {
		this->tail->next = node;
		node->previous = this->tail;
		this->tail = node;
		this->tail->next = NULL;
		this->length++;
	}
}
bool DLL::deleteElement(TValue info) {
	bool deleted = false;
	DLLNode *currentNode = this->head;
	while (currentNode != NULL && currentNode->info != info) {
		currentNode = currentNode->next;
	}
	if (currentNode != NULL) {
		if (currentNode == this->head) {
			this->head = this->head->next;
			this->head->previous = NULL;
			deleted = true;
		}
		else {
			if (currentNode == this->tail) {
				this->tail = this->tail->previous;
				this->tail->next = NULL;
				deleted = true;
			}
			else {
				currentNode->next->previous = currentNode->previous;
				currentNode->previous->next = currentNode->next;
				deleted = true;
			}
		}
	}
	if (deleted == true)
		this->length--;
	return deleted;
}

bool DLL::existingValue(TValue v) {
	int cnt = 0;
	DLLNode* node = this->head;
	while (node != NULL) {
		if (node->info == v) {
			cnt++;
			break;
		}
		node = node->next;
	}
	if (cnt)
		return true;
	return false;
}

TValue DLL::getFromPosition(int position) {
	int i = 0;
	TValue info = 0;
	DLLNode* node = this->head;
	while (i <= position) {
		info = node->info;
		node = node->next;
		i++;
	}
	return info;
}

DLL::~DLL() {
	DLLNode *node;
	while (this->head != NULL) {
		node = this->head->next;
		//delete this->head;
		this->length--;
		this->head = node;
	}
}