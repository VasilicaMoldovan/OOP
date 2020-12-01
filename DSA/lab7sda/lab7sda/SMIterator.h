#pragma once
#include "SortedMap.h"

class SMIterator
{
	friend class SortedMap;
private:
	SMIterator(const SortedMap& map);

	const SortedMap& map;
	BSTNode* current;
	BSTNode** elements;
	int c;

public:
	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();
	BSTNode* parent(BSTNode* node);
	BSTNode* succesor(BSTNode* node);

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;
};

