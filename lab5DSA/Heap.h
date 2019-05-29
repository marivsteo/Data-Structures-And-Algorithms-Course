#pragma once
#include "DynamicVector.h"
#include <iostream>
using namespace std;
typedef int TElem;
typedef bool(*Relation) (TElem e1, TElem e2);

class Heap
{
private:
	int cap;
	int len;
	DynamicVector vector;
public:

	int getLen() { return len; }
	DynamicVector getVector() { return vector; }
	bool(*rel)(TElem, TElem);
	Heap(int capcity, Relation r);
	void add(node k);
	int remove();

	//~Heap();
};