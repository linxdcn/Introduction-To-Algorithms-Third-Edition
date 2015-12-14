#include <iostream>
#include <stdlib.h>

using namespace std;

void Merge(int *data, int p, int q, int r)
{
    if(p==r)
        return;
    int data1[q-p+1];
    int data2[r-q];
    for(int i = 0; i != q - p + 1; i++)
        data1[i] = data[i + p];
    for(int i = 0; i != r-q; i++)
        data2[i] = data[q + 1 +i];
    int i = 0, j = 0, k = p;
    while( i != q - p + 1 && j != r - q)
    {
        if(data1[i] < data2[j])
        {
            data[k] = data1[i];
            i++;
        }
        else
        {
            data[k] = data2[j];
            j++;
        }
        k++;
    }
    if(i == q - p + 1)
    {
        while( j != r - q)
        {
            data[k] = data2[j];
            j++;
            k++;
        }
    }
    else
    {
        while( i != q - p + 1)
        {
            data[k] = data1[i];
            i++;
            k++;
        }
    }
}

void Mergesort(int *data, int p, int r)
{
    int q = (p + r) / 2;
    if(p < r)
    {
        Mergesort(data, p, q);
        Mergesort(data, q + 1, r);
    }
    Merge(data, p, q, r);
}

void print(int n, int *data)
{
    for(int i = 0; i != n; i++)
        cout << data[i] << " ";
    cout << endl;
}

int main()
{
    int const num = 100;
    int data[num];
    for(int i = 0; i != num; i++)
        data[i] = rand() % 100;
    int n = sizeof(data) / sizeof(data[0]);

    cout << "The original data is:" <<endl;
    print(n, data);

    Mergesort(data, 0, n-1);
    cout << "The sorted data is:" << endl;
    print(n, data);
    return 0;
}