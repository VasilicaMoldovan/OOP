#pragma once
#include <utility>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -1

typedef bool(*Relation)(TKey, TKey);
typedef TValue(*Transformer)(TKey, TValue);

class SMIterator;

struct BSTNode {
	TElem info;
	BSTNode *left;
	BSTNode *right;
};

class SortedMap {
	friend class SMIterator;
private:
	BSTNode *root;
	Relation relation;
	int sizeOfMap;
public:

	// implicit constructor
	SortedMap(Relation r);
	SortedMap(const SortedMap& map);

	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key does not exist, a new pair is added and the value null is returned
	TValue add(TKey c, TValue v);
	BSTNode* insertRec(BSTNode *node, TKey c, TValue v);
	BSTNode* initNode(TKey c, TValue v);

	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	TValue search(TKey c) const;

	//removes a key from the map and returns the value associated with the key if the key existed or null: NULL_TVALUE otherwise
	TValue remove(TKey c);
	BSTNode* removeRec(BSTNode* node, TKey c);
	BSTNode* minimum(BSTNode* node);
	
	//returns the number of pairs (key,value) from the map
	int size() const;

	//checks whether the map is empty or not
	bool isEmpty() const;

	// return the iterator for the map
	// the iterator will return the keys following the order given by the relation
	SMIterator iterator() const;

	void replaceAll(Transformer t);
	void replace(BSTNode *node, Transformer t);

	// destructor
	~SortedMap();
};
