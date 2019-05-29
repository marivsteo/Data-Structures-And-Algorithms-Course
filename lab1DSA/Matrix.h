#pragma once



typedef int TElem;
typedef int TElement;

#define NULL_TELEM 0



class Matrix {



private:

	/*representation of the matrix*/

	int n;
	int m;

	int* lines;
	int* cols;
	int* vals;

	int size;
	int capacity;

	static int numberElems;

public:

	//constructor

	//throws exception if nrLines or nrCols is negative or zero

	Matrix(int nrLines, int nrCols);


	//destructor

	~Matrix();


	//returns the number of lines

	int nrLines() const;



	//returns the number of columns

	int nrCols() const;



	//returns the element from line i and column j (indexing starts from 0)

	//throws exception if (i,j) is not a valid position in the Matrix

	TElem element(int i, int j) const;



	//modifies the value from line i and column j

	//returns the previous value from the position

	//throws exception if (i,j) is not a valid position in the Matrix

	TElem modify(int i, int j, TElem e);


};

