#include "SMIterator.h"
#include "SortedMap.h"
#include <stdexcept>

SMIterator::SMIterator(const SortedMap& map) : map(map)
{
	//The complexity is theta(n)
	this->current = map.root;
	this->c = 0;
	this->elements = new BSTNode*[this->map.sizeOfMap];
	for (int i = 0; i <= this->map.sizeOfMap; i++)
		this->elements[i] = NULL;
	BSTNode* node = map.root;
	int i = 0;
	while (node != NULL)
	{
		this->elements[i] = node;
		i++;
		node = this->succesor(node);
	}
}

void SMIterator::first()
{
	//The complexity is theta(1)
	this->current = this->map.root;
	this->c = 0;
}

BSTNode* SMIterator::parent(BSTNode* node)
{
	//The complexity is O(n)
	BSTNode* currentNode = this->map.root;

	if (currentNode == node)
		return NULL;
	else
	{
		while (currentNode != NULL && currentNode->left != node && currentNode->right != node)
		{
			if (!this->map.relation(currentNode->info.first, node->info.first))
				currentNode = currentNode->left;
			else
				currentNode = currentNode->right;
		}
		return currentNode;
	}
}

BSTNode* SMIterator::succesor(BSTNode* node)
{
	//The complexity is O(n) or O(n^2)
	BSTNode* currentNode;
	if (node->right != NULL)
	{
		currentNode = node->right;
		while (currentNode->left != NULL)
			currentNode = currentNode->left;
		return currentNode;
	}
	else
	{
		currentNode = node;
		BSTNode* p = this->parent(currentNode);
		while (p != NULL && p->left != currentNode)
		{
			currentNode = p;
			p = this->parent(p);
		}
		return p;
	}
}

void SMIterator::next()
{
	//The complexity is theta(1)
	if (this->valid() == false)
		throw std::invalid_argument("invalid iterator");
	else
	{
		this->c += 1;
		this->current = this->elements[c];
	}
}

bool SMIterator::valid() const
{
	//The complexity is theta(1)
	return (this->current != NULL);
}

TElem SMIterator::getCurrent() const
{
	//The complexity is theta(1)
	if (this->valid() == false)
		throw std::invalid_argument("invalid iterator");
	else
		return this->current->info;
}