#include "MultiMap.h"



MultiMap::MultiMap()
{
	this->m = 19;
	this->length = 0;
	this->T = new TElem[this->m];
	for (int i = 0; i < this->m; i++)
	{
		this->T[i].first = -1;
	}
}

void MultiMap::add(TKey c, TValue v)
{
	int f1 = this->h1(c);
	int f2 = this->h2(c);
	int i = 0;
	int pos = (f1 + i * f2) % this->m;
	while ((this->T[pos].first != -1 || this->T[pos].second.size() == 0) && i < this->m)
	{
		if (this->T[pos].first == c && this->T[pos].second.size() > 0)
		{
			this->T[pos].second.push_back(v);
			this->length++;
			break;
		}
		i++;
		pos = (f1 + i * f2) % this->m;
	}
	if (i == this->m)
		this->resizeAndRehash();
	else
	{
		if (this->T[pos].first == -1 && this->T[pos].second.size() == 0)
		{
			this->T[pos].first = c;
			this->T[pos].second.push_back(v);
			this->length++;
		}
	}
}

bool MultiMap::remove(TKey c, TValue v)
{
	bool found = false;
	int f1 = this->h1(c);
	int f2 = this->h2(c);
	int i = 0;
	int pos = (f1 + i * f2) % this->m;
	while ((this->T[pos].first != -1 || this->T[pos].second.size() == 0) && i < this->m && !found)
	{
		if (this->T[pos].first == c && this->T[pos].second.size() > 0)
		{
			for (int j = 0; j < this->T[pos].second.size(); j++)
			{
				if (this->T[pos].second[j] == v)
				{
					this->T[pos].second.erase(this->T[pos].second.begin() + j);
					found = true;
					this->length--;
					break;
				}
			}
		}
		i++;
		pos = (f1 + i * f2) % this->m;
	}
	return found;
}

vector<TValue> MultiMap::search(TKey c) const
{
	vector<TValue> result;
	int f1 = this->h1(c);
	int f2 = this->h2(c);
	int i = 0;
	int pos = (f1 + i * f2) % this->m;
	while ((this->T[pos].first != -1 || this->T[pos].second.size() == 0) && i < this->m)
	{
		if (this->T[pos].first == c && this->T[pos].second.size() > 0)
		{
			result = this->T[pos].second;
			break;
		}
		i++;
		pos = (f1 + i * f2) % this->m;
	}
	return result;
}

int MultiMap::size() const
{
	return this->length;
}

bool MultiMap::isEmpty() const
{
	return this->length == 0;
}

MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}

MultiMap::~MultiMap()
{
}

int MultiMap::h1(TKey c) const
{
	return abs(c) % this->m;
}

int MultiMap::h2(TKey c) const
{
	return 1 + (abs(c) % (this->m - 1));
}

void MultiMap::resizeAndRehash()
{

}