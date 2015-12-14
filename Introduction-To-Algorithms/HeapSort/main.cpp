#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "heap.h"

using namespace std;

int main()
{
    srand ( unsigned ( time ( NULL ) ) );
    int num = 10;
    Heap heap;
    for ( int i = 0; i != num; ++i)
        heap.push_back( rand() % 100 );

    cout << "The random heap is :" << endl;
    print( heap );
    Heapsort( heap );
    heap.reset_heapsize();
    cout << "The sorted heap is :" << endl;
    print( heap );
    return 0;
}