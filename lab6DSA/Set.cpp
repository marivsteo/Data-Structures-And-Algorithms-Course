#include<iostream>
#include"Set.h"

Set::Set() {
	sizeH = 100000;
	firstFree = 0;
	length = 0;
	this->table = new TElem[sizeH];
	this->next = new int[sizeH];

	for (int i = 0;i < sizeH;i++) {
		table[i] = INT_MAX;
		next[i] = INT_MAX;
	}
}

void Set::resize() {
	auto* old_table = table;
	int old_size = sizeH;
	sizeH *= 2;
	firstFree = 0;
	auto* new_table = new TElem[sizeH];
	auto* new_next = new int[sizeH];

	table = new_table;
	delete[] next;
	next = new_next;

	for (int i = 0;i < old_size;i++)
	{
		if (old_table[i] != INT_MAX) {
			int pos = hash(old_table[i]);
			if (table[pos] == INT_MAX) {
				table[pos] = old_table[i];
				next[pos] = INT_MAX;
				if (firstFree == pos)
					FindfirstFree();
			}
			else {
				int current = pos;
				while (next[current] != INT_MAX)
					current = next[current];
				table[firstFree] = old_table[i];
				next[current] = firstFree;
				FindfirstFree();
			}
		}
	}
	delete[] old_table;
}


//complexity: O(m), m is the size of the hashtable
void Set::FindfirstFree() {
	for (int i = 0;i < sizeH;i++) {
		if (table[i] == INT_MAX) {
			firstFree = i;
			break;
		}
	}
}


//complexity: Average case: theta(1), Worst case: theta(n)
bool Set::add(TElem e) {
	if (search(e))
		return false;

	if (firstFree == sizeH)
		resize();

	int pos = hash(e);
	if (table[pos] == INT_MAX) {
		table[pos] = e;
		next[pos] = INT_MAX;
		if (firstFree == pos)
			FindfirstFree();
	}
	else {
		int current = pos;
		while (next[current] != INT_MAX)
			current = next[current];
		table[firstFree] = e;
		next[firstFree] = INT_MAX;
		next[current] = firstFree;
		FindfirstFree();
	}
	length++;
	return true;
}


//complexity: O(m)
bool Set::remove(TElem e) {
	int pos = hash(e);
	int prev = INT_MAX;
	do {
		if (table[pos] == e) {
			table[pos] = INT_MAX;
			if (prev != INT_MAX)
				next[prev] = next[pos];
			length--;
			FindfirstFree();
			return true;
		}
		prev = pos;
		pos = next[pos];
	} while (pos != INT_MAX);
	return false;
}


//complexity: O(n)
bool Set::search(TElem e) const {
	int pos = hash(e);
	do {
		if (table[pos] == e)
			return true;
		pos = next[pos];
	} while (pos != INT_MAX);
	return false;
}

int Set::size() const {
	return length;
}

bool Set::isEmpty() const {
	return length == 0;
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}

Set::~Set() {
}