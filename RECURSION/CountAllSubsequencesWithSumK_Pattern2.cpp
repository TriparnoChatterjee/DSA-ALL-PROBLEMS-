#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    
    int f(int indx, int sum, int n, int k, vector<int> &arr)
    {
        if (indx == n)
        {
            if (sum == k)
            {
                return 1;
            }

            return 0;
        }
        int lr = 0;
        if (arr[indx] + sum <= k)
        {
           lr = f(indx + 1, arr[indx] + sum, n, k, arr);
        }
        int rr = f(indx + 1, sum, n, k, arr);
        return lr+rr;
    }
};
/*
    This code handles the case of zeros too but in another pattern where we have an integer as an return from the recursive function
 */
int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3 , 4 ,5};
    vector<int> temp;
    int sum = 0;
    vector<vector<int>> ans;
    cout<<s.f(0, sum, 5, 5, arr);
    return 0;
}