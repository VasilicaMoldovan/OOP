#pragma once
#include "dll.h"

class MultiMapIterator;

class MultiMap{
	friend class MultiMapIterator;
private:
	DLL *map;
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
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//return the element from a given position
	TElem giveElement(int position) const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;


	//descturctor
	//~MultiMap();
};


