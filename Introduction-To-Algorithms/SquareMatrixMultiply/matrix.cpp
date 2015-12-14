#include <iostream>
#include "matrix.h"

using namespace std;

int** NewMatrix(int row, int col)
{
    int** m;
    m = new int*[row];
    for(int i = 0; i != row; i++)
    {
        m[i] = new int[col];
    }
    return m;
}

void Print(int** m, int row, int col)
{
    for(int i = 0; i != row; i++)
    {
        for(int j = 0; j != col; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

int** Plus(int** A, int** B, int n)
{
    int** result = NewMatrix(n, n);
    for(int i = 0; i != n; i++)
        for(int j = 0; j != n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}
