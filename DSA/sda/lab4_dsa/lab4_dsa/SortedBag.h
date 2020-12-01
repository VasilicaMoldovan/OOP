#pragma once

typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);

class SortedBagIterator;

struct DLLANode {
	TElem info;
	TElem freq;
	int next;
	int prev;
};

class SortedBag {
private:
	friend class SortedBagIterator;
	/*representation of SortedBag*/
	DLLANode* nodes;
	int cap;
	int head;
	int tail;
	int firstEmpty;
	int lengthOfVector;
	int tempLength;
	Relation newRelation;
public:

	//constructor

	SortedBag(Relation r);
	SortedBag(const SortedBag &bag);


	int allocate();
	void free(int position);

	void insertAtPosition(TComp elem, int position);
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

	//destructor
	~SortedBag();
private:
	void resize(double factor = 1.5);
};