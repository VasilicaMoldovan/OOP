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

void DLL::push(TElem info) {
	DLLNode *node = new(DLLNode);
	node->info = info;
	node->next = NULL;
	node->previous = NULL;

	if (this->head = NULL) {
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

bool DLL::deleteElement(TElem info) {
	bool deleted = false;
	DLLNode *node, *aux;
	if (this->head->info == info) {
		node = this->head;
		this->head = this->head->next;
		this->head->previous = NULL;
		deleted = true;
	}
	else {
		aux = this->head;
		while (aux->next->next != NULL) {
			if (aux->next->info == info)
			{
				node = aux->next;
				aux->next = node->next;
				node->next->previous = aux;
				deleted = true;
			}
			aux = aux->next;
		}

		if (this->tail->info == info) {
			node = this->tail->previous;
			//this->tail->previous->next = NULL;
			this->tail = node;
			this->tail->next = NULL;
			deleted = true;
		}
	}
	return deleted;
}

vector<TValue> DLL::searchElement(TKey c) {
	vector<TValue> vect;
	vect = vector<TValue>(this->length + 1);
	DLLNode *node;
	node = this->head;
	while (node != NULL) {
		if (node->info.first == c) 
			vect.push_back(node->info.second);
		node = node->next;
	}
	return vect;
}

TElem DLL::getFromPosition(int position) {
	int i = 1;
	TElem info;
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
		delete this->head;
		this->length--;
		this->head = node;
	}
}