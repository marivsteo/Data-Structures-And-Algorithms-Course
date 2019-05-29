#include "Bag.h"

Bag::Bag() {
	//do nothing
}

void Bag::add(TElem e) {

	BagIterator it = this->items.getIterator();
	if (this->search(e))
		for (; it.valid(); it.next()) {
			if (e == it.getCurrent().element)
				it.getCurrent.freq++;
		}
	else
	{
		pair pair;
		pair.element = e;
		pair.freq = 0;
		this->items.addEnd(pair);
	}
}

bool Bag::remove(TElem e)
{
	if (!this->search(e)) return false;
	else {
		BagIterator it = this->items.getIterator();
		if (this->search(e))
			for (; it.valid(); it.next()) {
				if (e == it.getCurrent().element && it.getCurrent.freq != 1) {
					it.getCurrent.freq--;
					return true;
				}
				else if (e == it.getCurrent().element && it.getCurrent.freq == 1) {
					this->items.remove(e);
					return true;
				}
			}
	}
}

bool Bag::search(TElem e) const {
	return this->items.search(e);
}


int Bag::size() const {
	int count = 0;
	BagIterator it = this->items.getIterator();
	for (; it.valid(); it.next()) {
		int freq = it.getCurrent.freq;
		count += freq;
	}
}


bool Bag::isEmpty() const {
	return this->items.getSize() == 0;
}

int Bag::nrOccurrences(TElem e) const {
	/*int count = 0;
	BagIterator it = this->items.getIterator();
	for (; it.valid(); it.next()) {
		if (e == it.getCurrent()) {
			count++;
		}
	}
		return count;*/
	int freq = 0;
	BagIterator it = this->items.getIterator();
	if (this->search(e))
		for (; it.valid(); it.next()) {
			if (e == it.getCurrent().element)
				int freq = it.getCurrent.freq;
		}
	return freq;
}

BagIterator Bag::iterator() const {
	return this->items.getIterator();
}


Bag::~Bag() {}