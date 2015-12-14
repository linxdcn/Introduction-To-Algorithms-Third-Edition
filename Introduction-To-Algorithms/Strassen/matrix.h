#ifndef matrix_h
#define matrix_h

#include <iostream>

int** NewMatrix(int row, int col);
void Print(int** m, int row, int col);
int** Minus(int** A, int row1_top, int row1_bott, int col1_left, int col1_right,
            int** B, int row2_top, int row2_bott, int col2_left, int col2_right);
int** Plus(int** A, int row1_top, int row1_bott, int col1_left, int col1_right,
           int** B, int row2_top, int row2_bott, int col2_left, int col2_right);
#endif // matrix_h
