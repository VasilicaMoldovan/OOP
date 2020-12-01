#pragma once
#include <utility>

typedef int TElem;
typedef std::pair<TElem, int> TPair;

class BagIterator;

class Bag {
	friend class BagIterator;
private:
	TPair *T;
	int *next;
	int m;
	int firstFree;
	int nr;

public:

	//constructor

	Bag();
	Bag(const Bag &bag);

	void addAll(const Bag& b);

	//adds an element to the bag
	void add(TElem e);
	
	//removes one occurrence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e);

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e);

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
private:
	int h(TElem key);
	void resizeAndRehash();
	void changeFirstFree();
};