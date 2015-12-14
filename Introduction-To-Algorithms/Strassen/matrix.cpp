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

int** Minus(int** A, int row1_top, int row1_bott, int col1_left, int col1_right,
            int** B, int row2_top, int row2_bott, int col2_left, int col2_right)
{
    int rows1 = row1_bott - row1_top + 1;
    int rows2 = row2_bott - row2_top + 1;
    int cols1 = col1_right - col1_left + 1;
    int cols2 = col2_right - col2_left + 1;
    if(rows1 != rows2 || cols1 != cols2)
        return A;
    int** result = NewMatrix(rows1, cols1);
    for(int i = 0; i != rows1; i++)
        for(int j = 0; j != cols1; j++)
            result[i][j] = A[row1_top + i][col1_left + j] - B[row2_top + i][col2_left + j];
    return result;
}

int** Plus(int** A, int row1_top, int row1_bott, int col1_left, int col1_right,
           int** B, int row2_top, int row2_bott, int col2_left, int col2_right)
{
    int rows1 = row1_bott - row1_top + 1;
    int rows2 = row2_bott - row2_top + 1;
    int cols1 = col1_right - col1_left + 1;
    int cols2 = col2_right - col2_left + 1;
    if(rows1 != rows2 || cols1 != cols2)
        return A;
    int** result = NewMatrix(rows1, cols1);
    for(int i = 0; i != rows1; i++)
        for(int j = 0; j != cols1; j++)
            result[i][j] = A[row1_top + i][col1_left + j] + B[row2_top + i][col2_left + j];
    return result;
}
