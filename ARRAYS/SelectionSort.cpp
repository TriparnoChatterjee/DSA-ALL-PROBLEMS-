#include <bits/stdc++.h>
using namespace std;
#include "../helpers.h"
class Solution
{
public:
    void sort(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int curr_el = arr[i];
            int min_index = -1;
            if (i == arr.size() - 1)
                break;
            for (int j = i + 1; j < arr.size(); j++)
            {

                if (arr[j] < curr_el)
                {
                    curr_el = arr[j];
                    min_index = j;
                }
            }
            if (min_index != -1)
                swap(arr[i], arr[min_index]);
        }
    }
};
int main()
{
    Solution s;
    vector<int> arr = {5, 2, 1, 3, 4};
    s.sort(arr);
    Helpers helper;
    helper.printArray(arr);
    return 0;
}