#include "SortedMap.h"
#include "SMIterator.h"

void SortedMap::replace(BSTNode *node, Transformer t)
{
	//The complexity is theta(logn)
	if (node == NULL)
		return;
	node->info.second = t(node->info.first, node->info.second);
	this->replace(node->left, t);
	this->replace(node->right, t);
}

void SortedMap::replaceAll(Transformer t)
{
	//The complexity is theta(logn)
	this->replace(this->root, t);
}

SortedMap::SortedMap(Relation r)
{
	//The complexity is theta(1)
	this->relation = r;
	this->root = NULL;
	this->sizeOfMap = 0;
}

SortedMap::SortedMap(const SortedMap& map)
{
	//The complexity is theta(1)
	this->relation = map.relation;
	this->root = map.root;
	this->sizeOfMap = map.sizeOfMap;
}

BSTNode* SortedMap::initNode(TKey c, TValue v)
{
	//The complexity is theta(1)
	BSTNode *newNode = new BSTNode{};
	newNode->info.first = c;
	newNode->info.second = v;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

BSTNode* SortedMap::insertRec(BSTNode *node, TKey c, TValue v)
{
	//The complexity is O(n)
	if (node == NULL)
		node = this->initNode(c, v);
	else if (node->info.first == c)
	{
		BSTNode* aux = node;
		node->info.second = v;
		return aux;
	}
	else if (this->relation(node->info.first, c))
		node->right = this->insertRec(node->right, c, v);
	else
		node->left = this->insertRec(node->left, c, v);

	return node;
}

TValue SortedMap::add(TKey c, TValue v)
{
	//The complexity is O(n)
	TValue oldValue = this->search(c);
	if (this->root == NULL)
		this->root = this->insertRec(this->root, c, v);
	else
		this->insertRec(this->root, c, v);
	if (oldValue == NULL_TVALUE)
		this->sizeOfMap++;
	return oldValue;
}

TValue SortedMap::search(TKey c) const
{
	//The complexity is O(h)
	BSTNode *currentNode;
	currentNode = this->root;
	TValue value = NULL_TVALUE;
	bool found = false;

	while (currentNode != NULL && !found)
	{
		if (currentNode->info.first == c)
		{
			found = true;
			value = currentNode->info.second;
		}
		else if (this->relation(currentNode->info.first, c))
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}
	return value;
}

BSTNode* SortedMap::minimum(BSTNode* node)
{
	//The complexity is O(n)
	BSTNode *currentNode = node;

	if (currentNode == NULL)
		return NULL;
	else
	{
		while (currentNode->left != NULL)
			currentNode = currentNode->left;

		return currentNode;
	}
}

BSTNode* SortedMap::removeRec(BSTNode* node, TKey c)
{
	//The complexity is O(n)
	if (node == NULL)
		return NULL;
	else if (node->info.first == c)
	{
		if (node->left == NULL && node->right == NULL)
		{
			node = NULL;
			return NULL;
		}
		else if (node->left == NULL)
		{
			node = node->right;
			return node;
		}
		else if (node->right == NULL)
		{
			node = node->left;
			return node;
		}
		else
		{
			BSTNode* min = this->minimum(node->right);
			node->info = min->info;
			node->right = this->removeRec(node->right, min->info.first);
			return node;
		}
	}
	else if (this->relation(node->info.first, c))
	{
		node->right = this->removeRec(node->right, c);
		return node;
	}
	else
	{
		node->left = this->removeRec(node->left, c);
		return node;
	}
}

TValue SortedMap::remove(TKey c)
{
	//The complexity is O(n)
	TValue oldValue = this->search(c);
	if (this->root != NULL && this->root->info.first == c)
		this->root = this->removeRec(this->root, c);
	else
		this->removeRec(this->root, c);
	if (oldValue != NULL_TVALUE)
		this->sizeOfMap--;
	else
		if (c == -1)
			this->sizeOfMap--;
	return oldValue;
}

int SortedMap::size() const
{
	//The complexity is theta(1)
	return this->sizeOfMap;
}

bool SortedMap::isEmpty() const
{
	//The complexity is theta(1)
	return (this->sizeOfMap == 0);
}

SMIterator SortedMap::iterator() const
{
	//The complexity is theta(1)
	return SMIterator(*this);
}

SortedMap::~SortedMap()
{
	//The complexity is theta(1)
	delete[] this->root;
}