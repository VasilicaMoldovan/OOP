#include <assert.h>
#include <iostream>
#include "SortedMap.h"
#include "SMIterator.h"
#include "ShortTest.h"
#include <exception>
using namespace std;

bool relatie1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

TValue transf1(TKey k, TValue v)
{
	return (k + v) / 2;
}

void testAll() {
	SortedMap sm(relatie1);
	assert(sm.size() == 0);
	assert(sm.isEmpty());
	sm.add(1, 2);
	assert(sm.size() == 1);
	assert(!sm.isEmpty());
	assert(sm.search(1) != NULL_TVALUE);
	TValue v = sm.add(1, 3);
	assert(v == 2);
	assert(sm.search(1) == 3);
	SMIterator it = sm.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(e.second != NULL_TVALUE);
		it.next();
	}
	assert(sm.remove(1) == 3);
	assert(sm.isEmpty());

	SortedMap newMap(relatie1);
	for (int i = 0; i < 5; i++)
	{
		newMap.add(i, 3 * i);
	}
	newMap.replaceAll(transf1);
	for (int i = 0; i < 5; i++)
	{
		//cout << i << '\n';
		assert(newMap.search(i) == 2 * i);
	}
}

