#include <iostream>
#include <limits>

#define INFI std::numeric_limits<double>::max();

using namespace std;

void OptimalBST(double* p, double* q, double** e, double** w, int** solu, int nodeNum)
{
    for(int i = 1; i <= nodeNum + 1; i++)
    {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for(int distance = 0; distance < nodeNum; distance++)
    {
        for(int i = 1; i <= nodeNum - distance; i++)
        {
            w[i][i + distance] = w[i][i + distance - 1] + p[i + distance] + q[i + distance];
            for(int r = 0; r <= distance; r++)
            {
                double tmp =e[i][i + r - 1] + e[i + r + 1][i + distance] + w[i][i + distance];
                if(tmp < e[i][i + distance])
                {
                    e[i][i + distance] = tmp;
                    solu[i][i + distance] = i + r;
                }
            }
        }
    }
}

void Print(double** e, int** solu, int first, int second)
{
    if(first > second)
        return;

    Print(e, solu, first, solu[first][second] - 1);
    cout << solu[first][second] << "\t";
    Print(e, solu, solu[first][second] + 1, second);
}

int main()
{
    double p[] = {0, 0.15, 0.1, 0.05, 0.1, 0.2};
    double q[] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};
    const int nodeNum = sizeof(p) / sizeof(p[0]) - 1;
    double* e[nodeNum + 2];
    double* w[nodeNum + 2];
    int* solu[nodeNum + 2];
    for(int i = 0; i < nodeNum + 2; i++)
    {
        e[i] = new double[nodeNum + 2];
        w[i] = new double[nodeNum + 2];
        solu[i]= new int[nodeNum + 2];
        for(int j = 0; j < nodeNum + 2; j++)
        {
            e[i][j] = INFI;
            w[i][j] = 0;
            solu[i][j] = 0;
        }
    }
    OptimalBST(p, q, e, w, solu, nodeNum);
    cout << "The optimal value is:" << e[1][nodeNum] << endl;
    cout << "Solution is:";
    Print(e, solu, 1, nodeNum);

    return 0;
}
