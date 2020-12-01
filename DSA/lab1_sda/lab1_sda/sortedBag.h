#pragma once

typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);

class SortedBagIterator;

class SortedBag {
	friend class SortedBagIterator;
private:
	TComp *elements;
	int *frequency;
	int capacity;
	int lengthOfVector;
	Relation newRelation;
	/*representation of SortedBag*/
public:

	//constructor
	SortedBag(Relation r);

	SortedBag(const SortedBag &bag);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurrence of an element from a sorted bag
	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;
	//checks if the sorted bag is empty
	bool isEmpty() const;

	int elementsWithThisFrequency(int frequency) const;

	//destructor
	~SortedBag();
private:
	void resize(double factor = 1.5);
};

