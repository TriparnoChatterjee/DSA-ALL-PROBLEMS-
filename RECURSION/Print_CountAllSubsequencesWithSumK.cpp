#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int count = 0;
    void f(int indx, int sum, int n, int k, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (indx == n)
        {
            if (sum == k)
            {
                count++;
                ans.push_back(temp);
            }

            return;
        }
        if (arr[indx] + sum <= k)
        {
            temp.push_back(arr[indx]);
            f(indx + 1, arr[indx] + sum, n, k, arr, ans, temp);
            temp.pop_back();
        }
        f(indx + 1, sum, n, k, arr, ans, temp);
    }
};
/*
    This code handles the case of zeros in the array pattern 1 of handling count 
 */
int main()
{
    Solution s;
    vector<int> arr = {1, 2, 1};
    vector<int> temp;
    int sum = 0;
    vector<vector<int>> ans;
    s.f(0, sum, 3, 2, arr, ans, temp);
    for (const auto item : ans)
    {
        for (const auto el : item)
        {
            cout << el << ",";
        }
        cout << "\n";
    }
    cout << s.count;
    return 0;
}