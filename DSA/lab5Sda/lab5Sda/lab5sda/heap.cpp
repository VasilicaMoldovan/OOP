#include "heap.h"
#include <exception>
Heap::Heap()
{
	this->capacity = 10;
	this->length = 0;
	this->elements = new TElem[this->capacity];
}
void Heap::resize(double factor)
{
	//The total complexity is O(n)
	this->capacity *= factor;

	TElem *aux = new TElem[this->capacity];
	
	for (int i = 0; i < this->length; i++) {
		aux[i] = this->elements[i];
		
	}
	delete[] this->elements;
	elements = aux;
}
//O(log n) (+resize)
void Heap::add(TElem elem)
{
	if (this->length == this->capacity)
		this->resize(factor);
	this->elements[this->length + 1] = elem;
	this->length += 1;
	this->bubbleUp(this->length);

}
//O(log n)
void Heap::bubbleUp(int p)
{
	int pos = p;
	TElem elem = this->elements[p];
	int parent = p / 2;
	while (pos>0 && elem>this->elements[parent])
	{
		this->elements[pos] = this->elements[parent];
		pos = parent;
		parent = pos / 2;

	}
	this->elements[pos] = elem;
}
TElem Heap::remove()
{
	if (this->length == 0)
		throw std::exception("empty heap");

	TElem deletedElement = this->elements[0];
	this->elements[0] = this->elements[this->length];
	this->length -= 1;
	this->bubbleDown(0);
	return deletedElement;

}
void Heap::bubbleDown(int p)
{
	int pos = p;
	TElem elem = this->elements[p];
	while (pos < this->length - 1)
	{
		int maxChild = -1;
		if (pos * 2 < this->length)
			maxChild = pos * 2;
		if (pos * 2 + 1 < this->length&&this->elements[2 * pos + 1] > this->elements[2 * pos])
			maxChild = pos * 2 + 1;
		if (maxChild != -1 && this->elements[maxChild] > elem)
		{
			TElem tmp = this->elements[pos];
			this->elements[pos] = this->elements[maxChild];
			this->elements[maxChild] = tmp;
			pos = maxChild;

		}
		else
			pos = this->length + 1;

	}
}