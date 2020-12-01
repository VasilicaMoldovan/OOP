#pragma once
#include<vector>
#include<utility>
using namespace std;

typedef int TKey;
typedef int TValue;
typedef int TElem;
//typedef std::pair<TKey, TValue> TElem;

struct DLLNode {
	TElem info;
	DLLNode *previous;
	DLLNode *next;
};

class DLL {
private:
	DLLNode* head;
	DLLNode* tail;
	int length;

public:
	DLL();
	DLLNode* getHead();
	DLLNode* getTail();
	int getLength();
	void push(TElem info);
	bool deleteElement(TElem info);
	vector<TValue> searchElement(TKey c);
	TElem getFromPosition(int position);
	bool existingValue(TValue v);
	~DLL();
};