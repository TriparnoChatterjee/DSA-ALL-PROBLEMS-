#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSecondLargestElement(vector<int> &arr)
    {
        int first = arr[0];
        int second = -1e9;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > first)
            {
                second = first;
                first = arr[i];
            }
            else if (arr[i] != first and arr[i] > second)
            {
                second = arr[i];
            }
        }
        return second;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution s;
    cout << s.getSecondLargestElement(arr);
    return 0;
}