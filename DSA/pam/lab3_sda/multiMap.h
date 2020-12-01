#pragma once
#include "dll.h"

typedef std::pair<TKey, TValue> TElem;
typedef std::pair<TKey, DLL>TElement;

class MultiMapIterator;

struct Node {
	TElement info;
	Node *previous;
	Node *next;
};

class MultiMap{
	friend class MultiMapIterator;
private:
	Node* head;
	Node* tail;
	int sizeOfMap;
	/* representation of the MultiMap */
public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	//vector<TValue> search(TKey c) const;
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;
	int size2() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//return the element from a given position
	TElem giveElement(int position1, int position2) const;
	int getDllLength(int position) const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;


	//descturctor
	//~MultiMap();
};


