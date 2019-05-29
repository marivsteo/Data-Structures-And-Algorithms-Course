#pragma once
#include "LLAIterator.h"
#include "Bag.h"

class BagIterator {

	friend class Bag;

private:
	LLAIterator<pair> list_it;
public:
	BagIterator(LLAIterator<pair> it);

	bool valid() const;

	pair getCurrent() const;

	pair first();

	void next();
};