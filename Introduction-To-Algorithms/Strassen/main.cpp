#include <iostream>
#include "matrix.h"

using namespace std;

int** SquareStrassenMatrixMultiply(int** A, int** B, int length)
{
    int** R = NewMatrix(length,length);
    if(length == 1)
    {
        R[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int n = length / 2;
        int** S1 = Minus(B,0,n-1,n,length-1,B,n,length-1,n,length-1);
        int** S2 = Plus(A,0,n-1,0,n-1,A,0,n-1,n,length-1);
        int** S3 = Plus(A,n,length-1,0,n-1,A,n,length-1,n,length-1);
        int** S4 = Minus(B,n,length-1,0,n-1,B,0,n-1,0,n-1);
        int** S5 = Plus(A,0,n-1,0,n-1,A,n,length-1,n,length-1);
        int** S6 = Plus(B,0,n-1,0,n-1,B,n,length-1,n,length-1);
        int** S7 = Minus(A,0,n-1,n,length-1,A,n,length-1,n,length-1);
        int** S8 = Plus(B,n,length-1,0,n-1,B,n,length-1,n,length-1);
        int** S9 = Minus(A,0,n-1,0,n-1,A,n,length-1,0,n-1);
        int** S10 = Plus(B,0,n-1,0,n-1,B,0,n-1,n,length-1);

        int** A11 = NewMatrix(n,n);
        int** A22 = NewMatrix(n,n);
        int** B11 = NewMatrix(n,n);
        int** B22 = NewMatrix(n,n);
        for(int i = 0; i != n; i++)
            for(int j = 0; j != n; j++)
            {
                A11[i][j] = A[i][j];
                A22[i][j] = A[n+i][n+j];
                B11[i][j] = B[i][j];
                B22[i][j] = B[n+i][n+j];
            }

        int** P1 = SquareStrassenMatrixMultiply(A11,S1,n);
        int** P2 = SquareStrassenMatrixMultiply(S2,B22,n);
        int** P3 = SquareStrassenMatrixMultiply(S3,B11,n);
        int** P4 = SquareStrassenMatrixMultiply(A22,S4,n);
        int** P5 = SquareStrassenMatrixMultiply(S5,S6,n);
        int** P6 = SquareStrassenMatrixMultiply(S7,S8,n);
        int** P7 = SquareStrassenMatrixMultiply(S9,S10,n);

        int** C11_1 = Plus(P5,0,n-1,0,n-1,P4,0,n-1,0,n-1);
        int** C11_2 = Minus(P2,0,n-1,0,n-1,P6,0,n-1,0,n-1);
        int** C11 = Minus(C11_1,0,n-1,0,n-1,C11_2,0,n-1,0,n-1);
        int** C12 = Plus(P1,0,n-1,0,n-1,P2,0,n-1,0,n-1);
        int** C21 = Plus(P3,0,n-1,0,n-1,P4,0,n-1,0,n-1);
        int** C22_1 = Plus(P5,0,n-1,0,n-1,P1,0,n-1,0,n-1);
        int** C22_2 = Plus(P3,0,n-1,0,n-1,P7,0,n-1,0,n-1);
        int** C22 = Minus(C22_1,0,n-1,0,n-1,C22_2,0,n-1,0,n-1);
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
    int** result = SquareStrassenMatrixMultiply(A,B,length);

    cout << "Matrix A is :" << endl;
    Print(A, length, length);
    cout << "Matrix B is :" << endl;
    Print(B, length, length);
    cout << "A multiply B is :" << endl;
    Print(result, length, length);

    return 0;
}