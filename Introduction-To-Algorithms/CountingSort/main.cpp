#include <iostream>
#include <time.h>
#include <random>
using namespace std;

void CountingSort(int* A, const int num)
{
	int max = 0;
	for(int i = 0; i < num; i++)
		if(A[i] > max)
			max = A[i];
	int* B = new int[max+1];

	for(int i = 0; i < max + 1; i++)
        B[i] = 0;

	for(int i = 0; i < num; i++)
		B[A[i]]++;

	for(int i = 1; i < max + 1; i++)
		B[i] += B[i-1];

	int* C = new int[num];
	for(int i = num - 1; i >=0; i--)
	{
		B[A[i]]--;
		C[B[A[i]]] = A[i];

	}

	for(int i = 0; i < num; i++)
        A[i] = C[i];

	delete[] B;
	delete[] C;
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
	const int size = 100;
	srand ( unsigned ( time ( NULL ) ) );
	int A[size] = { };
	for(int i =0; i < size; i++)
		A[i] = rand() % 10;

	cout << "Original data is:" << endl;
	Print(A, size);

	CountingSort(A, size);
	cout << "Counting sort result:" << endl;
	Print(A, size);
	return 0;
}
