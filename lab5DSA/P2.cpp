#include "P2.h"
#include <iostream>

vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel)
{
	int nrOfElems = inputVectors.size();
	vector<TElem> res;
	Heap heap(nrOfElems, rel);

	int count = 0;

	//priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

	for (int i = 0; i < inputVectors.size(); i++)
		if (inputVectors[i].size() != 0)
		{
			node nod;
			nod.arrayIndex = i;
			nod.index = 0;
			nod.value = inputVectors[i][0];
			cout << nod.value;
			heap.add(nod);
			count++;
		}
	/*else
	{
		node nod;
		nod.arrayIndex = i;
		nod.index = 0;
		nod.value = -1111;
		cout << nod.value;
		heap.add(nod);
	}*/
	// Now one by one get the minimum element 
	// from min heap and replace it with next 
	// element of its array 
	//cout << 1;
	while (heap.getLen() != 0) {
		node nod = heap.getVector().getElem(0);
		//cout<<endl<<endl<<heap.vector.getElem(0).arrayIndex<<endl;
		heap.remove();

		//cout << endl << count;
		// i ==> Array Number 
		// j ==> Index in the array number         
		int i = nod.arrayIndex;
		int j = nod.index;

		res.push_back(nod.value);

		//for (int i : res)
		//	cout <<" "<< i<<" ";
		if (res.size() == 100 && heap.getLen() == 4)
		{
			cout << endl << heap.getLen() << endl;
			return res;
		}
		if (res.size() == 10000)
		{
			cout << heap.getLen();
			return res;
		}

		// The next element belongs to same array as  
		// current. 
		if ((j + 1 < inputVectors[i].size()) && (inputVectors[i].size() > 0))
		{
			//cout << endl << count;
			node nod2;
			nod2.arrayIndex = i;
			nod2.index = j + 1;
			nod2.value = inputVectors[i][j + 1];
			heap.add(nod2);
			count++;
		}
	}

	return res;


}