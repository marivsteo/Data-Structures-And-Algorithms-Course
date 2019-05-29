#pragma once

template <class U> class LLAIterator;

template<class T>
class LLA {

	//template <class U> 
	template <class U> friend class LLAIterator;

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
	T* elems;
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

	void addEnd(T e); 

	void addBegin(T e);

	void addBefore(T compElem, T toInsert);

	// Delete element on given index
	// O(1)
	void remove(T e);

	// Return iterator
	// O(1)
	LLAIterator<T> getIterator() const;

	// Get LLA size
	// O(1)
	int getSize() const;

	// Destructor
	~LLA();
};