#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

//get median through insert sort
int GetMedianIndex(int* A, vector<int> indexes)
{
    multimap<int,int> tmp_map;
    for(auto it = indexes.begin(); it != indexes.end(); it++)
        tmp_map.insert(multimap<int,int>::value_type(A[*it], *it));

    vector<int>::size_type nums = indexes.size();
    auto it_map = tmp_map.begin();
    if(nums % 2 == 1)
    {
        for(vector<int>::size_type i = 1; i < (nums - 1) / 2; i++ )
            it_map++;
        return it_map->second;
    }
    else
    {
        for(vector<int>::size_type i = 1; i < nums / 2; i++ )
            it_map++;
        return it_map->second;
    }
}

int FindIndex(int* A, vector<int> indexes)
{
    vector<int>::size_type nums = indexes.size();
    if(nums == 1)
        return indexes[0];

    vector<int> new_indexes;
    auto it = indexes.begin();
    while(it != indexes.end())
    {
        //There are more than 5 indexes left
        if(indexes.end() - it >= 5)
        {
            vector<int> indexes_part(it, it + 5);
            new_indexes.push_back(GetMedianIndex(A, indexes_part));
            it += 5;
        }
        else
        {
            vector<int> indexes_part(it, indexes.end());
            new_indexes.push_back(GetMedianIndex(A, indexes_part));
            it = indexes.end();
        }
    }
    return FindIndex(A, new_indexes);
}

int Partition(int* A, int p, int q)
{
    if(p==q)
        return p;
    int i = p;
    int j = p;
    for(; j < q; j++)
    {
        if(A[j] < A[q])
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[q]);
    return i;
}

int GroupPartition(int* A, int p, int q)
{
    vector<int> indexes;
    for(int i = p; i <= q; i++)
        indexes.push_back(i);

    int index = FindIndex(A, indexes);
    swap(A[index], A[q]);
    return Partition(A, p, q);
}

int RandomizedSelect(int* A, int p, int q, int order)
{
    if(p <= q)
    {
        int sep = GroupPartition(A, p, q);

        if((sep - p + 1) == order)
            return A[sep];

        if((sep - p + 1) < order)
            return RandomizedSelect(A, sep + 1, q, order -sep + p -1);
        else
            return RandomizedSelect(A, p, sep - 1, order);
    }
}

void Print(int* A, int size)
{
    for(int i = 0; i < size; i++)
        if(size % 10 == 9)
            cout << A[i] << endl;
        else
            cout << A[i] << "\t";
}

int main()
{
    const int size = 10;
    const int order = 5;
    srand( unsigned ( time(NULL)));
    int A[size] = {};
    for(int i = 0; i < size; i++)
        A[i] = rand() % 10;
    cout << "Origin data is :" << endl;
    Print(A, size);
    int reuslt = RandomizedSelect(A, 0, size - 1, order);
    cout << "The result is :" << endl << reuslt << endl;
    return 0;
}
