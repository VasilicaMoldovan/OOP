#include "ShortTest.h"
#include <assert.h>
#include "Bag.h"
#include "BagIterator.h"


void testAll() {
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0);
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}

	// addAll
	Bag b2;
	assert(b2.isEmpty() == true);
	b2.add(13);
	b2.add(15);
	b2.add(13);
	b2.add(17);
	Bag b3;
	assert(b3.isEmpty() == true);
	b3.add(13);
	b3.addAll(b2);
	assert(b3.search(17) == true);
	assert(b3.nrOccurrences(13) == 3);
	assert(b3.remove(15) == true);
	assert(b3.remove(15) == false);
}
