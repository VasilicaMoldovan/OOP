#pragma once

typedef int TElem;

class Heap
{
private:
	int capacity;
	int length;
	TElem* elements;

public:
	Heap();
	void add(TElem elem);
	void bubbleUp(int pos);
	TElem remove();
	void bubbleDown(int pos);
	int getSize() { return this->length; }
	~Heap() {};

private:
	void resize(double factor);
	double factor = 2;

};