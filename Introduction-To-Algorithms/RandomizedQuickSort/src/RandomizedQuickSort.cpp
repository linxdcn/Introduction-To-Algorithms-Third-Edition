//============================================================================
// Name        : RandomizedQuickSort.cpp
// Author      : Xiaodong Lin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Partision(int* A, int first, int last)
{
	auto i = first;
	if(first == last)
		return first;
	else
	{
		for(auto j = first; j != last; j++)
		{
			if(A[j] <= A[last])
			{
				swap(A[i],A[j]);
				i++;
			}
		}
		swap(A[i],A[last]);
		return i;
	}
}

int RandomizedPartision(int* A, int first, int last)
{
	int num = last - first + 1;
	int inc = rand() % num;
	swap(A[first + inc],A[last]);
	return Partision(A, first, last);
}

void RandomizedQuickSort(int* A, int first, int last)
{
	if(first < last)
	{
		int i = RandomizedPartision(A, first, last);
		RandomizedQuickSort(A, first, i - 1);
		RandomizedQuickSort(A, i + 1, last);
	}
	return;
}

void Print(int* A, int size)
{
	for(int i = 0; i < size; i++)
		if(i % 10 == 9)
			cout << A[i] << endl;
		else
			cout << A[i] << "\t" ;
}

int main()
{
	const int size = 50;
	srand ( unsigned ( time ( NULL ) ) );
	int A[size] = { };
	for(int i =0; i < size; i++)
		A[i] = rand() % 100;

	cout << "Original data is:" << endl;
	Print(A, size);

	RandomizedQuickSort(A, 0, size - 1);
	cout << "Quick sort result:" << endl;
	Print(A, size);
	return 0;
}
