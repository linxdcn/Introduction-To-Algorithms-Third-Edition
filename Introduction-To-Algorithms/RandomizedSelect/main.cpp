#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

int Partition(int* A, int p, int q)
{
    if(p==q)
        return p;
    int i = p;
    int j = p;
    for(; j < q; j++)
    {
        if(A[j] < A[q])
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[q]);
    return i;
}

int RandomizedPartition(int* A, int p, int q)
{
    int div = q - p + 1;
    int index = p + rand() % div;
    swap(A[index], A[q]);
    return Partition(A, p, q);
}

int RandomizedSelect(int* A, int p, int q, int count)
{
    if(p <= q)
    {
        int sep = RandomizedPartition(A, p, q);

        if((sep - p + 1) == count)
            return A[sep];

        if((sep - p + 1) < count)
            return RandomizedSelect(A, sep + 1, q, count -sep + p -1);
        else
            return RandomizedSelect(A, p, sep - 1, count);
    }
}

void Print(int* A, int size)
{
    for(int i = 0; i < size; i++)
        if(size % 10 == 9)
            cout << A[i] << endl;
        else
            cout << A[i] << "\t";
}

int main()
{
    const int size = 10;
    const int mid = 5;
    srand( unsigned ( time(NULL)));
    int A[size] = {};
    for(int i = 0; i < size; i++)
        A[i] = rand() % 10;
    cout << "Origin data is :" << endl;
    Print(A, size);
    int reuslt = RandomizedSelect(A, 0, size - 1, mid);
    cout << "The result is :" << endl << reuslt << endl;
    return 0;
}
