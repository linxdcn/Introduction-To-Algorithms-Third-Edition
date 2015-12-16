#include <iostream>

using namespace std;

//size of result is (p+1)*(q+1)
//p is the number of the char in A
//q is the number of the char in B
void LCS(char* A, char* B, int** result, int p, int q)
{
    for(int i = 0; i < p; i++)
        result[i][0] = 0;
    for(int j = 0; j < q; j++)
        result[0][j] = 0;

    for(int i = 1; i <= p; i++)
    {
        for(int j = 1; j <= q; j++)
        {
            if(A[i - 1] == B[j - 1])
                result[i][j] = result[i - 1][j - 1] + 1;
            else if(result[i][j - 1] < result[i - 1][j])
                result[i][j] = result[i - 1][j];
            else
                result[i][j] = result[i][j - 1];
        }
    }
}

void Print(char* A, char* B, int** result, int p, int q)
{
    if(p < 1 || q < 1)
        return;

    if(A[p - 1] == B[q - 1])
    {
        Print(A, B, result, p - 1, q - 1);
        cout << A[p - 1];
    }
    else if(result[p][q - 1] <= result[p - 1][q])
        Print(A, B, result, p - 1, q);
    else
        Print(A, B, result, p, q - 1);
}
int main()
{
    char A[] = "ABCBDAB";
    char B[] = "BDCABA";
    int p = sizeof(A) / sizeof(A[0]) - 1;
    int q = sizeof(B) / sizeof(B[0]) - 1;

    int* result[p + 1];
    for(int i = 0; i <= p; i++)
    {
        result[i] = new int[q + 1];
        for(int j = 0; j <= q; j++)
            result[i][j] = 0;
    }
    LCS(A, B, result, p, q);
    cout << "The longest number is:" << result[p][q] << endl;
    cout << "The longest common subsequence is:";
    Print(A, B, result, p , q);
    cout << endl;
    return 0;
}
