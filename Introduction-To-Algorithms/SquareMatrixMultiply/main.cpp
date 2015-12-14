#include <iostream>
#include "matrix.h"

using namespace std;

int** SquareStrassenMatrixMultiply(int** A, int row1_top, int row1_bott, int col1_left, int col1_right,
                                   int** B, int row2_top, int row2_bott, int col2_left, int col2_right)
{
    int rows1 = row1_bott - row1_top + 1;
    int rows2 = row2_bott - row2_top + 1;
    int cols1 = col1_right - col1_left + 1;
    int cols2 = col2_right - col2_left + 1;
    int** R = NewMatrix(rows1,cols1);
    if(rows1 != rows2 || cols1 != cols2)
        return R;
    if(rows1 == 1 && cols1 == 1)
    {
        R[0][0] = A[row1_top][col1_left] * B[row2_top][col2_left];
    }
    else
    {
        int n = rows1 / 2;
        int** C11 = Plus(SquareStrassenMatrixMultiply(A,row1_top,row1_top+n-1,col1_left,col1_left+n-1,
                                                 B,row2_top,row2_top+n-1,col2_left,col2_left+n-1),
                         SquareStrassenMatrixMultiply(A,row1_top,row1_top+n-1,col1_left+n,col1_right,
                                                 B,row2_top+n,row2_bott,col2_left,col2_left+n-1),
                         n);
        int** C12 = Plus(SquareStrassenMatrixMultiply(A,row1_top,row1_top+n-1,col1_left,col1_left+n-1,
                                                 B,row2_top,row2_top+n-1,col2_left+n,col2_right),
                         SquareStrassenMatrixMultiply(A,row1_top,row1_top+n-1,col1_left+n,col1_right,
                                                 B,row2_top+n,row2_bott,col2_left+n,col2_right),
                         n);
        int** C21 = Plus(SquareStrassenMatrixMultiply(A,row1_top+n,row1_bott,col1_left,col1_left+n-1,
                                                 B,row2_top,row2_top+n-1,col2_left,col2_left+n-1),
                         SquareStrassenMatrixMultiply(A,row1_top+n,row1_bott,col1_left+n,col1_right,
                                                 B,row2_top+n,row2_bott,col2_left,col2_left+n-1),
                         n);
        int** C22 = Plus(SquareStrassenMatrixMultiply(A,row1_top+n,row1_bott,col1_left,col1_left+n-1,
                                                 B,row2_top,row2_top+n-1,col2_left+n,col2_right),
                         SquareStrassenMatrixMultiply(A,row1_top+n,row1_bott,col1_left+n,col1_right,
                                                 B,row2_top+n,row2_bott,col2_left+n,col2_right),
                         n);
        for(int i = 0; i != n; i++)
            for(int j = 0; j != n; j++)
            {
                R[i][j] = C11[i][j];
                R[i][n+j] = C12[i][j];
                R[n+i][j] = C21[i][j];
                R[n+i][n+j] = C22[i][j];
            }
    }
    return R;
}

int main()
{
    int index = 2;
    int length = 1;
    for(int i = 0; i != index; i++)
        length = length * 2;
    int** A = NewMatrix(length,length);
    int** B = NewMatrix(length,length);
    for(int i = 0; i != length; i++)
        for(int j = 0; j != length; j++)
            A[i][j] = 1;
    for(int i = 0; i != length; i++)
        for(int j = 0; j != length; j++)
            B[i][j] = i + j;
    int** result = SquareStrassenMatrixMultiply(A,0,length-1,0,length-1,B,0,length-1,0,length-1);

    cout << "Matrix A is :" << endl;
    Print(A, length, length);
    cout << "Matrix B is :" << endl;
    Print(B, length, length);
    cout << "A multiply B is :" << endl;
    Print(result, length, length);
    return 0;
}
