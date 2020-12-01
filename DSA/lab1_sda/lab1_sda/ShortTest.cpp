#include "ShortTest.h"
#include "sortedBag.h"
#include "iterator.h"
#include <assert.h>
#include <iostream>
using namespace std;

bool relation1(TComp e1, TComp e2) {
	return e1 <= e2;
}

void testAll() {
	SortedBag sb(relation1);
	sb.add(5);
	sb.add(6);
	sb.add(0);
	sb.add(5);
	sb.add(10);
	sb.add(8);

	assert(sb.size() == 6);
	assert(sb.nrOccurrences(5) == 2);

	
	assert(sb.remove(5) == true);
	assert(sb.size() == 5);

	assert(sb.search(6) == true);
	assert(sb.isEmpty() == false);

	SortedBagIterator it = sb.iterator();
	assert(it.valid() == true);
	while (it.valid()) {
		it.getCurrent();
		it.next();
	}
	assert(it.valid() == false);
	it.first();
	assert(it.valid() == true);

	SortedBag sb2(relation1);
	sb2.add(12);
	sb2.add(12);
	sb2.add(12);
	sb2.add(15);
	sb2.add(15);
	sb2.add(15);
	sb2.add(4);
	sb2.add(4);
	sb2.add(3);
	sb2.add(3);
	sb2.add(1);
	sb2.add(1);
	sb2.add(2);
	sb2.add(2);
	sb2.add(17);

	assert(sb2.elementsWithThisFrequency(3) == 2);
	assert(sb2.elementsWithThisFrequency(2) == 4);
	assert(sb2.elementsWithThisFrequency(1) == 1);
	cout << "done";
}
/*
int main() {
	testAll();
	return 0;
}*/