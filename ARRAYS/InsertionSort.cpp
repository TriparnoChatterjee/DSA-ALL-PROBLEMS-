#include <bits/stdc++.h>
#include "../helpers.h"
using namespace std;
class Solution
{
public:
    void sort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j != 0 && arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
};
int main()
{
    Helpers h;
    Solution s;
    vector<int> arr = {5, 2, 3, 1, 4};
    s.sort(arr);
    h.printArray(arr);
    return 0;
}