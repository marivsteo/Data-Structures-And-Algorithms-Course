#pragma once
#include "LinkedListArray.h"
#include<exception>

#define yeet throw

template <class U> class LLA;

template<class T>
class LLAIterator {

	template <class U> friend class LLA;

private:
	const LLA<T>& c;
	int it;

	LLAIterator(const LLA<T>& c);

public:

	// Iterate forward
	// O(1)
	void next();
	
	T first();

	// Get current element
	// O(1)
	T getCurrent() const;

	// Check valid
	// O(1)
	bool valid() const;

};