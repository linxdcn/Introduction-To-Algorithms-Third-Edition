#include <iostream>
#include <algorithm>
#include "heap.h"

using namespace std;

void Heap::push_back( double x )
{
    _heapsize += 1;
    data.push_back( x );
}

int Parent ( int i )
{
    return i / 2;
}
int Left ( int i )
{
    return 2 * i;
}
int Right ( int i )
{
    return 2 * i + 1;
}

void print ( Heap A )
{
    for ( int i = 1; i != A.heapsize() + 1; ++i )
        cout << A[i] << " ";
    cout << endl;
}

void MaxHeapify ( Heap& A, int i )
{
    int l = Left( i );
    int r = Right( i );
    int largest = i;
    if ( A[i] < A[l] && l <= A.heapsize() )
    {
        largest = l;
    }
    if ( A[largest] < A[r] && r <= A.heapsize() )
    {
        largest = r;
    }
    if ( largest != i)
    {
        swap ( A[i], A[largest] );
        MaxHeapify( A, largest );
    }
}

void BuildMaxHeap ( Heap& A )
{
    int n = A.size() / 2;
    for ( int i = n; i != 0; --i)
        MaxHeapify( A, i );
}

void Heapsort ( Heap& A )
{
    BuildMaxHeap( A );
    for ( int i = A.size(); i != 1; --i)
    {
        swap ( A[1], A[i] );
        A.set_heapsize( A.heapsize() - 1 );
        MaxHeapify( A, 1 );
    }
}

double HeapMaximum ( Heap& A )
{
    return A[1];
}

double HeapExtractMax ( Heap& A )
{
    if ( A.heapsize() < 1 )
        cout << "heap underflow!" << endl;

    double max = A[1];
    A[1] = A[A.heapsize()];
    A.set_heapsize( A.heapsize() - 1 );
    MaxHeapify( A, 1 );
    return max;
}

void HeapIncreaseKey ( Heap& A, int i, double key )
{
    if ( key < A[i] )
        cout << "new key is smaller than current key!" << endl;
    A[i] = key;
    while ( i > 1 && A[Parent(i)] < A[i] )
    {
        swap ( A[i], A[Parent(i)] );
        i = Parent(i);
    }
}

void MaxHeapInsert ( Heap A, double key )
{
    A.set_heapsize( A.heapsize() + 1 );
    A[A.heapsize()] = -1000000;
    HeapIncreaseKey( A, A.heapsize(), key );
}

