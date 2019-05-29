#pragma once
#include"SetIterator.h"
#include<stdlib.h>


typedef int TElem;

class SetIterator;



class Set {

	friend class SetIterator;

private:

	/* representation of Set*/
	TElem* table;
	int* next;
	int sizeH;
	int firstFree;
	int length;

	int hash(TElem e) const { return abs(e % sizeH); }

	void FindfirstFree();
	void resize();


public:

	//implicit constructor

	Set();



	//adds an element to the  set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false

	bool add(TElem e);



	//removes an element from the set

	//if the element was removed, it returns true, otherwise false

	bool remove(TElem e);



	//checks if an element is in the  set

	bool search(TElem elem) const;



	//returns the number of elements;

	int size() const;



	//checks if the set is empty

	bool isEmpty() const;



	//returns an iterator for the set

	SetIterator iterator() const;



	//destructor

	~Set();



};