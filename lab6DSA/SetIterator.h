#pragma once
#include "Set.h"

typedef int TElem;

class Set;

class SetIterator {

	friend class Set;

private:

	const Set& set;
	int current;

private:
	SetIterator(const Set& set);
public:

	bool valid() const;

	TElem getCurrent() const;

	void first();

	void next();

	
};