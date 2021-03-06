#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
#include "LLAIterator.h"
#include"LinkedListArray.h"

#define yeet throw

template <class T>

	void LLA<T>::resize() {
		int newCap = this->capacity * 2;
		T* auxElems = new T[newCap];
		int* auxNext = new int[newCap];
		int* auxStack = new int[newCap];

		std::copy(this->elems + 0, this->elems + this->capacity, auxElems + 0);
		std::copy(this->next + 0, this->next + this->capacity, auxNext + 0);
		for (int i = this->capacity; i < newCap; i++) {
			auxStack[++this->stackHead] = i;
		}

		delete[] this->elems;
		this->elems = auxElems;

		delete[] this->next;
		this->next = auxNext;

		delete[] this->stack;
		this->stack = auxStack;

		this->capacity = newCap;
	}

	/*void LLA::print() {
		pair current = this->head;
		std::cout << this->head << " | ";
		while (current != -1) {
			std::cout << current << ' ' << this->elems[current] << ' ' << this->next[current] << " - ";
			current = this->next[current];
		}
		std::cout << "|\n";
	}
	*/
	template <class T>
	// Constructor
	// O(1)
	LLA<T>::LLA() {
		this->capacity = 100;
		this->stackHead = -1;
		this->head = -1;
		this->size = 0;

		this->elems = new T[this->capacity];
		this->next = new int[this->capacity];
		this->stack = new int[this->capacity];

		for (int i = 0; i < this->capacity; i++) {
			this->stack[++stackHead] = i;
		}
	}

	template<class T>
	// Element lookup
	// O(N)
	bool LLA<T>::search(int e) const {
		int current = this->head;
		while (current != -1 && this->elems[current] != e) {
			current = this->next[current];
		}

		return current != -1;
	}

	template<class T>
	void LLA<T>::addEnd(T e) {
		if (this->stackHead == -1) this->resize();

		if (this->head == -1) {
			this->addBegin(e);
			return;
		}

		int current = this->head;
		while (this->next[current] != -1) current = this->next[current];

		int freeIndex = this->stack[this->stackHead--];

		this->next[current] = freeIndex;
		this->next[freeIndex] = -1;
		this->elems[freeIndex] = e;
		this->size++;
	}

	template<class T>
	void LLA<T>::addBegin(T e) {
		if (this->stackHead == -1) this->resize();

		int freeIndex = this->stack[this->stackHead--];

		this->elems[freeIndex] = e;
		this->next[freeIndex] = this->head;
		this->head = freeIndex;
		this->size++;

	}

	template<class T>
	void LLA<T>::addBefore(T compElem, T toInsert) {
		if (this->stackHead == -1) this->resize();

		if (this->elems[this->head] == compElem) {
			addBegin(toInsert);
			return;
		}

		int current = this->head;
		while (current != -1 && this->elems[this->next[current]] != compElem) {
			current = this->next[current];
		}

		// (1) -> (2)
		// (1) -> (3) -> (2)
		int auxNext = this->next[current]; // Idx of (2)
		int freeIndex = this->stack[this->stackHead--]; // Idx of (3)

		this->next[current] = freeIndex; // (1) -> (3)
		this->elems[this->next[current]] = toInsert; // Insert val into (3)
		this->next[this->next[current]] = auxNext; // (3) -> (2)
		this->size++;

	}

	template<class T>
	// Delete element on given index
	// O(1)
	void LLA<T>::remove(T e) {
		if (!this->search(e)) yeet std::exception();

		if (this->elems[this->head] == e) {
			this->stack[++this->stackHead] = this->head;
			this->head = this->next[this->head];
			this->size--;
			return;
		}

		int current = this->head;
		while (current != -1 && this->elems[this->next[current]] != e)
			current = this->next[current];

		this->stack[++this->stackHead] = this->next[current];
		this->next[current] = this->next[this->next[current]];
		this->size--;
	}

	template<class T>
	// Return iterator
	// O(1)
	LLAIterator<T> LLA<T>::getIterator() const {
		return LLAIterator(*this);
	}

	template<class T>
	// Get LLA size
	// O(1)
	int LLA<T>::getSize() const {
		return this->size;
	}

	template<class T>
	// Destructor
	LLA<T>::~LLA() {
		delete[] this->elems;
		delete[] this->stack;
		delete[] this->next;
	}