#include <iostream>
#include <list>
#include <random>
#include <time.h>

using namespace std;

void InsertToList(list<double>& insertList, double value);

void BuckeySort(int* A, int size)
{
    //transfer to 0.xxx
    double max = 100;
    double* B = new double[size];
    for(int i = 0; i < size; i++)
        B[i] = (double)A[i] / max;

    list<double>* array_list = new list<double>[size];

    for(int i = 0; i < size; i++)
    {
        InsertToList(array_list[(int)(B[i]*size)],B[i]);
    }

    int count = 0;
    for(int i = 0; i < size; i++)
    {
        auto it_begin = array_list[i].begin();
        auto it_end = array_list[i].end();
        while(it_begin != it_end)
        {
            A[count] = *it_begin * max;
            count++;
            it_begin++;
        }
    }
    delete[] B;
    delete[] array_list;
}

void InsertToList(list<double>& insertList, double value)
{
    auto it_begin = insertList.begin();
    auto it_end = insertList.end();
    while(it_begin != it_end)
        if(*it_begin > value)
        {
            insertList.insert(it_begin,value);
            break;
        }
        else
        {
            it_begin++;
        }
    if(it_begin == it_end)
        insertList.insert(it_begin,value);
}

void Print(int* A, int size)
{
	for(int i = 0; i < size; i++)
		if(i % 10 == 9)
			cout << A[i] << endl;
		else
			cout << A[i] << "\t" ;
}

int main()
{
	const int size = 10;
	srand ( unsigned ( time ( NULL ) ) );
	int A[size] = { };
	for(int i =0; i < size; i++)
		A[i] = rand() % 100;

	cout << "Original data is:" << endl;
	Print(A, size);

	BuckeySort(A, size);
	cout << "Counting sort result:" << endl;
	Print(A, size);
	return 0;
}
