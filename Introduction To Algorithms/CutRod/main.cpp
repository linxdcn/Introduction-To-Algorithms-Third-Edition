#include <iostream>

using namespace std;

struct UnitPrice
{
    int num;
    int* price;

    UnitPrice()
    {
        num = 10;
        int tmp[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
        price = tmp;
    }
};

void CutRod(UnitPrice* unitPrice, int length, int* result, int* solu)
{
    result[0] = 0;
    for(int i = 1; i <= length; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(i > unitPrice->num)
            {
                int rest = i % unitPrice->num;
                int max_count = (i - rest) / unitPrice->num;
                result[i] = max_count * unitPrice->price[unitPrice->num - 1] + result[rest];
            }
            else
            {
                int tmp = unitPrice->price[j - 1] + result[i - j];
                if(tmp > result[i])
                {
                    result[i] = tmp;
                    solu[i] = j;
                }
            }
        }
    }
}
void OutputSolution(int* solu, int n)
{
    if(n > 0)
    {
        cout << solu[n] << "\t";
        OutputSolution(solu, n - solu[n]);
    }

}
int main()
{
    const int length = 7;
    UnitPrice* unitPrice = new UnitPrice();
    int result[length + 1] = {};
    int solu[length + 1] = {};
    CutRod(unitPrice, length, result, solu);
    delete unitPrice;

    for(int i = 1; i <= length; i++)
    {
        cout << "Length of rod is:" << i << ", the optimal price is:" << result[i] << endl;
        cout << "Solution is:";
        OutputSolution(solu, i);
        cout << endl;
    }
    return 0;
}
