#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

void print( vector<int>::const_iterator vbeg, vector<int>::const_iterator vend )
{
    while ( vbeg != vend )
    {
        cout << *vbeg << " ";
        ++vbeg;
    }
    cout << endl;
}

int main()
{
    srand( unsigned ( time ( NULL ) ) );

    vector<int> data;
    for ( int i = 0; i != 10; ++i)
        data.push_back( i );
    cout << "Original data is :" << endl;
    print ( data.begin(), data.end() );

    for ( int i = 0; i != 10; ++i)
    {
        int k = rand() % ( 10 - i ) + i;
        swap ( data[i], data[k]);
    }
    cout << "Randomized data is :" << endl;
    print ( data.begin(), data.end() );
    return 0;
}