#include "Matrix.h"

Matrix::Matrix(int nrLines, int nrCols)
{

	if (nrLines < 0 || nrCols < 0)
		throw"These numbers can not be 0!";

	this->n = nrLines;
	this->m = nrCols;

	this->lines = new int[nrLines + 1];
	this->cols = new int[1];
	this->vals = new int[1];

	size = 0;
	capacity = 1;
}

Matrix::~Matrix() {
	delete[] this->lines;
	delete[] this->cols;
	delete[] this->vals;
}

int Matrix::nrLines() const
{
	return this->n;
}

int Matrix::nrCols() const
{
	return this->m;
}

TElem Matrix::element(int i, int j) const
{
	int k = 0, l = 1;
	while (i > this->lines[k] && i < this->lines[l])
	{
		k++;
		l++;
	}

	for (int x = k; x < l;x++)
		if (this->cols[x] == j)
			return vals[x];
	return 0;

	/*if (i < 0 || i > n || j < 0 || j > m)
		throw"Invalid position!";

	for (int x = 0; x<this->n + 1; x++)
		for (int y = 0;y<this->lines[x + 1] && y<size; y++)
			if (i == x && j == this->cols[y])
				return vals[y];
	return 0;*/
}

TElem Matrix::modify(int i, int j, TElem e)
{
	if (i < 0 || i > n || j < 0 || j > m)
		throw"Invalid position!";

	int k=0, l=0, pos=0, prev=0;
	k = this->lines[i];
	l = this->lines[i + 1];
	if (element(i, j) != 0 && e == 0)
	{
		int ok = true;
		for (int x = k; x < l && ok;x++)
		{
			if (this->cols[x] == j)
				pos = x;
				prev = this->vals[pos];
				ok = false;
		}
		for (int x = pos;x < this->size - 1;x++)
		{
			this->cols[x] = this->cols[x + 1];
			this->vals[x] = this->vals[x + 1];
			size--;
		}
		for (int x = 0;x < n + 1;x++)
			this->lines[x] -= 1;

		return prev;
	}
	else if (e != 0 && element(i, j) == 0)
	{
		for (int x = k; x < l;x++)
			if (this->cols[x + 1] > j)
				pos = x;
		prev = this->vals[pos + 1];

		for (int x = size + 1;x < pos;x++)
		{
			this->cols[x] = this->cols[x - 1];
			this->vals[x] = this->vals[x - 1];
			size++;
		}
		this->cols[pos + 1] = j;
		this->vals[pos + 1] = e;

		return prev;
	}

	else if (element(i, j) != 0 && e != 0)
	{
		prev = this->vals[j];
		this->vals[j] = e;
		return prev;
	}
	/*int ok = 1, k = 0, l = 1;
	int pos = 0;
	if (i < 0 || i > n || j < 0 || j > m)
		throw"Invalid position!";

	if (e != 0 && element(i, j) == 0)
	{
		while (i > this->lines[k] && i < this->lines[l])
		{
			k++;
			l++;
		}

		for (int x = k; x < l;x++)
			if (this->cols[x+1] > j)
				pos = x;
		int prev = this->vals[pos + 1];

		for (int x = size+1;x < pos;x++)
		{
			this->cols[x] = this->cols[x - 1];
			this->vals[x] = this->vals[x - 1];
			size++;
		}
		this->cols[pos + 1] = j;
		this->vals[pos + 1] = e;

		return prev;
	}
	
	else if (element(i, j) != 0 && e == 0)
	{
		
		while (i > this->lines[k] && i < this->lines[l])
		{
			k++;
			l++;
		}

		for (int x = k; x < l;x++)
			if (this->cols[x] == j)
				pos = x;
		int prev = this->vals[pos];
		
		for (int x = pos;x < this->size-1;x++)
		{
			this->cols[x] = this->cols[x + 1];
			this->vals[x] = this->vals[x + 1];
			size--;
		}
		for (int x = 0;x < n + 1;x++)
			this->lines[x] -= 1;

		return prev;
	}
	
	else if (element(i, j) != 0 && e != 0)
	{
		int prev = this->vals[j];
		this->vals[j] = e;
		return prev;
	}*/
}
