#ifndef heap_h
#define heap_h

#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Heap
{
private:

public:
    explicit Heap( ) : data ( 0 ) { };
    const int heapsize() { return _heapsize; }
    const int size() { return data.size(); }
    void push_back( double x );

    void set_heapsize ( int n ) { _heapsize = n; }
    void reset_heapsize () { _heapsize = data.size(); }
    const double& operator[] ( int x ) const { return data[x-1]; }
    double& operator[] ( int x ) { return data[x-1]; }

protected:
    vector<double> data;
    int _heapsize = 0;
};

int Parent ( int i );
int Left ( int i );
int Right ( int i );
void print ( Heap A );
void MaxHeapify ( Heap& A, int i );
void BuildMaxHeap ( Heap& A );
void Heapsort ( Heap& A );
double HeapMaximum ( Heap& A );
double HeapExtractMax ( Heap& A );
void HeapIncreaseKey ( Heap& A, int i, double key );
void MaxHeapInsert ( Heap& A, double key );

#endif // heap_h
