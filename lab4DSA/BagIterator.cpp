#include "BagIterator.h"
#include "LinkedListArray.h"
#include <exception>

BagIterator::BagIterator(LLAIterator<pair> it) : list_it{ it } {}

bool BagIterator::valid() const {
	return this->list_it.valid();
}


pair BagIterator::getCurrent() const {
	if (!this->list_it.valid()) throw std::exception();
	return this->list_it.getCurrent();
}

pair BagIterator::first() {
	return this->list_it.first();
}

void BagIterator::next() {
	if (!this->list_it.valid()) throw std::exception();
	this->list_it.next();
}