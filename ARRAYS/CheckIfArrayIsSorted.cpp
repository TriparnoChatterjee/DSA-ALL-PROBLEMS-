#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int isSorted(int n, vector<int> arr)
    {
        // Write your code here.
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    cout<<s.isSorted(5,{1,2,2,3,4});
    return 0;
}