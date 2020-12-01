#include "Bag.h"
#include "BagIterator.h"

void Bag::addAll(const Bag& b) 
{
	//The complexity is theta(m ) where m is the dimension of the bag b + the complexity of resizeRehash if needed +
	// the complexity of changeFirstFree
	int aux = 0;
	int pos = 0;
	int prev = -1;
	for (int i = 0; i < b.m; i++)
	{
		if (b.T[i].first != -1 || b.T[i].second > 0)
		{
			aux = b.T[i].second;
			pos = this->h(b.T[i].first);

			while (pos != -1)
			{
				if (this->T[pos].first == b.T[i].first && this->T[pos].second > 0)
				{
					this->T[pos].second += aux;
					break;
				}
				prev = pos;
				pos = this->next[pos];
			}
			if (pos == -1)
			{
				if (prev == -1)
				{
					this->T[this->firstFree].first = b.T[i].first;
					this->T[this->firstFree].second = b.T[i].second;
					this->next[this->firstFree] = -1;
					this->changeFirstFree();
					if (this->firstFree == this->m)
						this->resizeAndRehash();
				}
				else
				{
					this->T[this->firstFree].first = b.T[i].first;
					this->T[this->firstFree].second = b.T[i].second;
					this->next[prev] = this->firstFree;
					this->next[firstFree] = -1;
					this->changeFirstFree();
					if (this->firstFree == this->m)
						this->resizeAndRehash();
				}
			}
		}
	}
}

Bag::Bag()
{
	//The complexity is theta(m)
	this->m = 23;
	this->nr = 0;
	this->T = new TPair[this->m];
	this->next = new int[this->m];
	this->firstFree = 0;
	for (int i = 0; i < this->m; i++) {
		this->next[i] = -1;
		this->T[i] = std::make_pair(-1, -1);
	}
}

Bag::Bag(const Bag &bag) {
	//The complexity is theta(m)
	this->m = bag.m;
	this->nr = bag.nr;
	this->firstFree = bag.firstFree;
	this->T = new TPair[this->m];
	this->next = new int[this->m];
	for (int i = 0; i < this->m; i++)
	{
		this->T[i] = bag.T[i];
		this->next[i] = bag.next[i];
	}
}

int Bag::h(TElem key) {
	//The complexity is theta(1)
	return (abs(key) % m);
}

void Bag::resizeAndRehash()
{
	//The complexity is theta(m)
	int length = this->m;
	int aux1 = this->nr;
	this->m *= 2;
	this->m++;

	TPair *auxPairs = new TPair[this->m];
	int *auxNext = new int[this->m];
	for (int i = 0; i < this->m; i++)
	{
		auxNext[i] = -1;
		auxPairs[i] = std::make_pair(-1, -1);
	}

	TPair *elems = new TPair[length];
	for (int i = 0; i < length; i++)
		elems[i] = this->T[i];

	delete[] this->T;
	delete[] this->next;

	next = auxNext;
	T = auxPairs;

	for (int i = 0; i < length; i++) 
	{
		if (elems[i].first != -1 || elems[i].second > 0)
		{
			int aux = elems[i].second;
			while (aux > 0)
			{
				this->add(elems[i].first);
				aux--;
			}
		}
	}
	this->nr = aux1;
}

void Bag::changeFirstFree() {
	//The complexity is theta(m)
	this->firstFree = this->firstFree + 1;
	while (this->firstFree < this->m && (this->T[this->firstFree].first != -1 || this->T[this->firstFree].second > 0))
		this->firstFree = this->firstFree + 1;
}

void Bag::add(TElem e) {
	//The complexity is O(n)
	int pos = this->h(e);
	if (this->T[pos].first == -1 && this->T[pos].second == -1)
	{
		this->T[pos] = std::make_pair(e, 1);
		this->next[pos] = -1;
		if (this->firstFree == pos)
			this->changeFirstFree();
	}
	else
	{
		int current = pos;
		while (current != -1)
		{
			if (this->T[current].first == e && this->T[current].second > 0)
			{
				this->T[current].second += 1;
				break;
			}
			current = this->next[current];
		}

		if (current == -1)
		{
			if (this->firstFree >= this->m)
				this->resizeAndRehash();

			current = pos;
			while (this->next[current] != -1)
				current = this->next[current];
			this->T[this->firstFree].first = e;
			this->T[this->firstFree].second = 1;
			this->next[this->firstFree] = -1;
			this->next[current] = this->firstFree;
			this->changeFirstFree();
		}
		//this->changeFirstFree();
	}
	this->nr += 1;
}

bool Bag::remove(TElem e)
{
	bool deleted = false;

	int i = this->h(e);
	int j = -1;
	int index = 0;

	while (i != -1)
	{
		if (e == -1)
		{
			if (this->T[i].first == e && this->T[i].second > 0)
				break;
		}
		else
		{
			if (this->T[i].first == e)
				break;
		}
		j = i;
		i = this->next[i];
	}

	if (i == -1)
		deleted = false;
	else
	{
		this->T[i].second--;
		if (this->T[i].second == 0)
		{
			bool over = false;
			int p, pp;
			do {
				p = this->next[i];
				pp = i;

				while (p != -1 && this->h(this->T[p].first) != i)
				{
					pp = p;
					p = this->next[p];
				}

				if (p == -1)
					over = true;
				else
				{
					this->T[i] = this->T[p];
					j = pp;
					i = p;
				}
			} while (!over);

			while (index < this->m && j == -1)
			{
				if (this->next[index] == i)
					j = index;
				else
					index++;
			}


			if (j != -1)
				this->next[j] = this->next[i];
			this->T[i] = std::make_pair(-1, -1);
			this->next[i] = -1;
			if (this->firstFree > i)
				this->firstFree = i;
		}
		deleted = true;
		this->nr--;
	}
	return deleted;
}

bool Bag::search(TElem e) 
{
	//The complexity is O(n)
	int pos = this->h(e);
	bool found = false;
	if (this->T[pos].first == e && this->T[pos].second > 0)
		found = true;
	else
	{
		while (pos != -1 && !found)
		{
			if (this->T[pos].first == e && this->T[pos].second > 0)
				found = true;
			pos = this->next[pos];
		}
	}
	return found;
}

int Bag::nrOccurrences(TElem e)
{
	//The complexity is O(n)
	int pos = this->h(e);
	int nr = 0;
	if (this->T[pos].first == e && this->T[pos].second > 0)
		nr = this->T[pos].second;
	else
	{
		while (pos != -1)
		{
			if (this->T[pos].first == e && this->T[pos].second > 0)
			{
				nr = this->T[pos].second;
				break;
			}
			pos = this->next[pos];
		}
	}
	return nr;
}

int Bag::size() const {
	//The complexity is theta(1)
	return this->nr;
}

BagIterator Bag::iterator() const {
	//The complexity is theta(1)
	return BagIterator(*this);
}

bool Bag::isEmpty() const {
	//The complexity is theta(1)
	if (this->nr == 0)
		return true;
	return false;
}

Bag::~Bag()
{
	delete[] this->T;
	delete[] this->next;
}
