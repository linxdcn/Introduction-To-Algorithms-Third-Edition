#include <iostream>
#include <stdlib.h>

using namespace std;

void print_data(int n, int *data)
{
    for(int i = 0; i != n; i++)
    {
        cout << data[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int const num = 100;
    int data[num];
    for(int i = 0; i != num; i++)
        data[i] = rand() % 100;
    int n = sizeof(data) / sizeof(data[0]);

    cout << "The original data is:" <<endl;
    print_data(n, data);

    for(int j = 2; j != n; j++)
    {
        int temp = data[j];
        int i = j-1;
        while(i > -1 && data[i] > temp)
        {
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = temp;
    }

    cout << "The sorted data is:" << endl;
    print_data(n, data);
    return 0;
}