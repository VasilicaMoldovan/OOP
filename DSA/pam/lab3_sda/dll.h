#pragma once
#include<vector>
#include<utility>
using namespace std;

typedef int TKey;
typedef int TValue;
//typedef std::pair<TKey, TValue> TElem;

struct DLLNode {
	TValue info;
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
	void push(TValue info);
	bool deleteElement(TValue info);
	vector<TValue> searchElement(TKey c);
	TValue getFromPosition(int position);
	bool existingValue(TValue v);
	~DLL();
};