#pragma once
//#include "Song.h"



struct node
{
	int arrayIndex = 0;
	int index = 0;
	int value = 0;
};


class DynamicVector
{
private:
	node* elems;
	int size;
	int capacity;

public:


	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(const node& e);
	node getElem(int pos) { return this->elems[pos]; }
	void setElem(int pos, node value) { this->elems[pos] = value; }
	int getSize() const;
	node* getAllElems() const;

	//private:
		// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};
