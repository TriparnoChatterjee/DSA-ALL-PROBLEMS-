#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void getAllSubsequences(int index, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int n)
    {
        if (index >= n)
        {
            // base case
            ans.push_back(temp);
            return;
        }
        // take
        temp.push_back(arr[index]);
        getAllSubsequences(index + 1, arr, temp, ans, n);
        temp.pop_back();
        // don't - take
        getAllSubsequences(index + 1, arr, temp, ans, n);
    }
};
int main()
{
    vector<int> arr(4);
    int c = 1;
    for (int i = 0; i < 4; i++)
        arr[i] = c++;
    vector<int> temp;
    vector<vector<int>> ans;
    Solution s;
    s.getAllSubsequences(0, arr, temp, ans, 4);
    for (const auto item : ans)
    {
        for (const auto el : item)
        {
            cout << el << ",";
        }
        cout << "\n";
    }
    return 0;
}