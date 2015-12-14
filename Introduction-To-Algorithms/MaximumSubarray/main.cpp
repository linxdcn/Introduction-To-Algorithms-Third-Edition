#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Result
{
    vector<int>::size_type left_index;
    vector<int>::size_type right_index;
    int max_sum;
};

Result FindCrossMaximumSubarray(vector<int> data, vector<int>::size_type first, vector<int>::size_type mid, vector<int>::size_type last)
{
    vector<int>::size_type left_index;
    vector<int>::size_type right_index;
    vector<int>::size_type left_count = mid;
    vector<int>::size_type right_count = mid;
    int left_temp = data[mid];
    int right_temp = data[mid];
    int left_max = data[mid];
    int right_max = data[mid];
    while(left_count != first)
    {
        left_count--;
        left_temp += data[left_count];
        if(left_max < left_temp)
        {
            left_index = left_count;
            left_max = left_temp;
        }
    }
    while(right_count != last)
    {
        right_count++;
        right_temp += data[right_count];
        if(right_max < right_temp)
        {
            right_index = right_count;
            right_max = right_temp;
        }
    }
    Result rs;
    rs.left_index = left_index;
    rs.right_index = right_index;
    rs.max_sum = right_max + left_max - data[mid];
    return rs;
}

Result FindMaxmumSubarray(vector<int> data, vector<int>::size_type first, vector<int>::size_type last)
{
    vector<int>::size_type mid = (first + last) / 2;
    if(last > first)
    {
        Result result1 = FindMaxmumSubarray(data, first, mid);
        Result result2 = FindMaxmumSubarray(data, mid + 1, last);
        Result result3 = FindCrossMaximumSubarray(data, first, mid, last);
        if(result1.max_sum > result2.max_sum && result1.max_sum > result3.max_sum)
            return result1;
        else if(result2.max_sum > result1.max_sum && result2.max_sum > result3.max_sum)
            return result2;
        else
            return result3;
    }
    else
    {
        Result _result;
        _result.left_index = first;
        _result.right_index = last;
        _result.max_sum = data[first];
        return _result;
    }
}

int main()
{
    vector<int> data({13,-2,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7});
    Result result = FindMaxmumSubarray(data, 0, data.size()-1);
    cout << result.max_sum << endl;
    return 0;
}