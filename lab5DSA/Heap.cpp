#include "Heap.h"

Heap::Heap(int capacity, Relation r)
{
	this->len = 0;
	this->cap = capacity;
	this->vector = DynamicVector(cap);
	this->rel = r;
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleUp(Heap heap, int p)
//heap - a heap
//p - position from which we bubble the new node up
{
	int poz = p;
	node elem;
	elem = heap.getVector().getElem(p);
	int parent;
	if (p == 0)
		parent = 0;
	else
		parent = (p - 1) / 2;

	while (poz > 0 && heap.rel(elem.value, heap.getVector().getElem(parent).value) == true)
	{//move parent down

		heap.getVector().setElem(poz, heap.getVector().getElem(parent));
		poz = parent;

		parent = (poz - 1) / 2;
	}
	heap.getVector().setElem(poz, elem);

}
void bubbleDown(Heap heap, int p)
{
	//heap - is a heap
	//p - position from which we move down the element
	int poz = p;
	node elem = heap.getVector().getElem(p);

	while (poz <heap.getLen())
	{
		//cout << 1;
		int maxChild = -1;
		if (poz * 2 + 1 < heap.getLen())

			maxChild = poz * 2 + 1;

		if (poz * 2 + 2 < heap.getLen() && heap.rel(heap.getVector().getElem(2 * poz + 2).value, heap.getVector().getElem(2 * poz + 1).value) == true)
			//it has two children and the right is greater
			maxChild = poz * 2 + 2;

		if (maxChild != -1 && heap.rel(heap.getVector().getElem(maxChild).value, elem.value) == true)
		{
			heap.getVector().setElem(poz, heap.getVector().getElem(maxChild));
			poz = maxChild;
		}
		else
		{
			heap.getVector().setElem(poz, elem);
			//poz = heap.len + 1;
			break;
		}

	}
}


void Heap::add(node k)
{
	//heap - a heap
	//e - the element to be added
	if (this->len == this->cap)
	{
		this->vector.resize();
		this->cap = this->cap * 2;

	}

	this->vector.add(k);
	this->len = this->len + 1;
	if (this->len>=2)
		bubbleUp(*this, this->len);
	//bubbleUp(*this, this->len-1);

}
/*
void bubbleDown(Heap heap, int p)
{
	//heap - is a heap
	//p - position from which we move down the element
	int poz = p;
	node elem = heap.vector.getElem(p);
	//int maxChild = -1;
	while (poz < heap.len)
	{
		cout << 1;
		int maxChild = -1;
		if (poz * 2 <= heap.len)

			maxChild = poz * 2;

		if (poz * 2 + 1 <= heap.len && heap.vector.getElem(2 * poz + 1).value > heap.vector.getElem(2 * poz).value)
		//it has two children and the right is greater
			maxChild = poz * 2 + 1;


		if (maxChild != -1 && heap.vector.getElem(maxChild).value> elem.value)
		{
			heap.vector.setElem(poz, heap.vector.getElem(maxChild));
			poz = maxChild;
		}
		else
			poz = heap.len + 1;

	}
}

void bubbleDown(Heap heap, int p)
{
	//heap - is a heap
	//p - position from which we move down the element
	int poz = p;
	node elem = heap.vector.getElem(p);

	while (poz < heap.len)
	{
		cout << 1;
		int maxChild = -1;
		if (poz * 2 <= heap.len)

			maxChild = poz * 2;

		if (poz * 2 + 1 <= heap.len && heap.rel(heap.vector.getElem(2 * poz + 1).value, heap.vector.getElem(2 * poz).value)==false)
			//it has two children and the right is greater
			maxChild = poz * 2 + 1;

		if (maxChild != -1 && heap.rel(heap.vector.getElem(maxChild).value , elem.value)==false)
		{
			heap.vector.setElem(poz, heap.vector.getElem(maxChild));
			poz = maxChild;
		}
		else
			poz = heap.len + 1;

	}
}*/

int Heap::remove()
{
	//heap - is a heap
	if (this->len == 0)
		return -1;
	int deletedElem = this->vector.getElem(0).value;
	this->vector.setElem(0, this->vector.getElem(this->len));
	this->len = this->len - 1;
	bubbleDown(*this, 0);
	//cout << 1;
	return deletedElem;
}
