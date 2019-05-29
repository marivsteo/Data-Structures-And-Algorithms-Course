#pragma once
#pragma once

class LLAIterator;

struct pair {
	int element;
	int frequency;
};

class LLA {

	//template <class U> 
	friend class LLAIterator;

	/*
	  LLA
	  addBefore
	  remove
	  get
	  insert
	  getIterator
	  getSize
	*/
private:
	int size;
	int capacity;
	pair* elems;
	int* next;
	int* stack;
	int stackHead;
	int head;


public:

	// O(N), container elements must be moved to new array
	// Throws if `newCap` smaller than current number of elements
	void resize();

	void print();

	// Constructor
	// O(1)
	LLA();

	// Element lookup
	// O(N)
	bool search(int e) const;

	void addEnd(int e);

	void addBegin(int e);

	void addBefore(int compElem, int toInsert);

	// Delete element on given index
	// O(1)
	void remove(int e);

	// Return iterator
	// O(1)
	LLAIterator getIterator() const;

	// Get LLA size
	// O(1)
	int getSize() const;

	// Destructor
	~LLA();
};