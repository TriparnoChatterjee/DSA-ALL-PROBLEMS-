#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int n = arr.size();
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                if (flag == false)
                {
                    flag = true;
                }
                else
                    return false;
            }
        }
        if (flag == false)
            return true;
        // check if the last element is lesser than the 0th element
        return arr[n - 1] <= arr[0];
    }
};
int main()
{
    Solution s;
    // first find the junction point of the array and check if the dip is happening only once or not
    return 0;
}