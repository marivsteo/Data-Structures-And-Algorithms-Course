#pragma once

#include"LLAIterator.h"
#include "LinkedListArray.h"

#define yeet throw

	template<class T>
	// Constructor
	// O(1)
	LLAIterator<T>::LLAIterator(const LLA<T>& list) : c{ list } {
		this->it = c.head;
	}

	template<class T>
	// Iterate forward
	// O(1)
	void LLAIterator<T>::next() {
		if (!this->valid()) yeet std::exception();

		this->it = this->c.next[this->it];
	}

	template<class T>
	T LLAIterator<T>::first() {
		int first = this->c.head;
		this->it = this->c.head;
		return first;
	}

	template<class T>
	// Get current element
	// O(1)
	T LLAIterator<T>::getCurrent() const {
		if (!this->valid()) throw std::exception();

		return this->c.elems[this->it];
	}

	template<class T>
	// Check valid
	// O(1)
	bool LLAIterator<T>::valid() const {
		return this->it != -1;
	}