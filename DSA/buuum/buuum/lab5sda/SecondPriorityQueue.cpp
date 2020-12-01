#include "SecondPriorityQueue.h"
#include<exception>
//implicit constructor
SecondPriorityQueue::SecondPriorityQueue(Relation r)
{
	//The total complexity is theta(1)
	this->capacity = 10;
	this->length = 0;
	this->elements = new Element[this->capacity];
	this->relation = r;

}

//adds an element with a priority to the queue
void SecondPriorityQueue::push(TElem e, TPriority p)
{
	//The total complexity is O(logn) + resize(theta(n)) => theta(n)
	if (this->length+1 == this->capacity)
		//resize
	{
		this->capacity *= 2;
		Element *aux = new Element[this->capacity];
		for (int i = 0; i <= this->length; i++) {
			aux[i] = this->elements[i];

		}
		delete[] this->elements;
		this->elements = aux;
	}
	this->elements[this->length + 1] = std::make_pair(e,p);
	this->length += 1;
	//bubble-up
	int position = this->length;
	int pos = position;
	Element elem = this->elements[position];
	int parent = position / 2;
	while (pos > 1 && this->relation(elem.second,this->elements[parent].second)==true)
	{
		this->elements[pos] = this->elements[parent];
		pos = parent;
		parent = pos / 2;

	}
	this->elements[pos] = elem;

}

//returns the element with the second highest priority with respect to the relation
//throws exception if the queue has less than 2 elements
Element SecondPriorityQueue::top()  const
{
	//The total complexity is theta(1)
	if (this->length < 2)
		throw std::exception("not enough elements");
	if(this->length == 2 || this->relation(this->elements[2].second, this->elements[3].second))
		return this->elements[2];
	else return this->elements[3];

}

//removes and returns the element with the second highest priority
//throws exception if the queue has less than 2 elements
Element SecondPriorityQueue::pop()
{
	//The total complexity is O(logn)
	if (this->length < 2)
		throw std::exception("not enough elements");
	int p = 2;
	Element deletedElement;
	if (this->length==2 || this->relation(this->elements[2].second, this->elements[3].second))
		p = 2;
	else p = 3;
	deletedElement = this->elements[p];
	this->elements[p] = this->elements[this->length];
	this->length -= 1;
	//bubble-down
	int pos = p;
	Element elem = this->elements[p];
	while (pos < this->length)
	{
		int maxChild = -1;
		if (pos * 2 <= this->length)
			maxChild = pos * 2;
		if (pos * 2 + 1 <= this->length && this->relation(this->elements[2 * pos + 1].second,this->elements[2 * pos].second))
			maxChild = pos * 2 + 1;
		if (maxChild != -1 && this->relation(this->elements[maxChild].second, elem.second))
		{
			Element tmp = this->elements[pos];
			this->elements[pos] = this->elements[maxChild];
			this->elements[maxChild] = tmp;
			pos = maxChild;

		}
		else
			pos = this->length + 1;

	}
	return deletedElement;
}

//checks if the queue has at most one element
bool SecondPriorityQueue::atMostOne() const
{
	//The total complexity is theta(1)
	if (this->length > 1)
		return false;
	return true;

}

//destructor
SecondPriorityQueue::~SecondPriorityQueue()
{
	//The total complexity is theta(1)
	delete[] this->elements;
}