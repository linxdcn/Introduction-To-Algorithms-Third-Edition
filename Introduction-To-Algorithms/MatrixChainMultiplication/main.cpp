#include <iostream>
#include <limits>

#define INFTY std::numeric_limits<int>::max()

using namespace std;

void MatrixChain(int* p, int** result, int** solu, int num)
{
    for(int i = 0; i < num; i++)
        result[i][i] = 0;

    for(int i = 1; i < num; i++)
    {
        for(int j = 1; j <= num - i; j++)
        {
            for(int r = j; r < j + i; r++)
            {
                int tmp = result[j - 1][r - 1] + result[r][j + i - 1] + p[j - 1] * p[r] * p[j + i];
                if(result[j - 1][j + i - 1] > tmp)
                {
                    result[j - 1][j + i - 1] = tmp;
                    solu[j - 1][j + i - 1] = r;
                }
            }
        }
    }
}

void Print(int** solu, int n, int m)
{
    if(solu[n][m] != 0)
    {
        int tmp = solu[n][m];
        cout << tmp << "\t";
        Print(solu, n, tmp - 1);
        Print(solu, tmp, m);
    }
}
int main()
{
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    const int num = sizeof(p) / sizeof(p[0]) - 1;
    int* result[num];
    int* solu[num];
    for(int i = 0; i < num; i++)
    {
        result[i] = new int[num];
        solu[i] = new int[num];

        for(int j = 0; j < num; j++)
        {
            result[i][j] = INFTY;
            solu[i][j] = 0;
        }
    }
    MatrixChain(p, result, solu, num);
    cout << "Optimal result is:" << result[0][5] << endl;
    cout << "Solution is:";
    Print(solu, 0, 5);
    cout << endl;

    delete[] result;
    delete[] solu;
    return 0;
}
