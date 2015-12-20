#include <iostream>
#include <vector>

using namespace std;

void Select(int** t, int num, vector<int>* result)
{
    int a = 0;
    int end_t = 0;

    while(a < num)
    {
        if(t[0][a] >= end_t)
        {
            result->push_back(a + 1);
            end_t = t[1][a];
        }
        a = a + 1;
    }
}
int main()
{
    int time[2][11] = {1,3,0,5,3,5,6,8,8,2,12,4,5,6,7,9,9,10,11,12,14,16};
    int* t[2];
    vector<int>* result =  new vector<int>;
    for(int i = 0; i < 2; i++)
        t[i] = time[i];

    Select(t, 11, result);
    cout << "The number of the activities are:" << result->size() << endl;
    for(auto tbegin = result->begin(); tbegin != result->end(); tbegin++)
        cout << *tbegin << "\t";
    delete result;
    return 0;
}
