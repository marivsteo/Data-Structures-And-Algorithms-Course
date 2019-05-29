#include<iostream>
#include"SetIterator.h"

SetIterator::SetIterator(const Set& set) : set(set) {
	first();
}

void SetIterator::first() {
	for (int i = 0;i < set.sizeH;i++) {
		if (set.table[i] != INT_MAX) {
			current = i;
			break;
		}
	}
}

void SetIterator::next() {
	current += 1;
	while (set.table[current] == INT_MAX && current < set.sizeH)
		current += 1;
}

bool SetIterator::valid() const {
	if (set.isEmpty())
		return false;
	return current < set.sizeH;
}

TElem SetIterator::getCurrent() const {
	return set.table[current];
}