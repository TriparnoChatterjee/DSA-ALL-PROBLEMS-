#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> mergeSortedArrays(vector<int> left, vector<int> right)
    {
        int left_ptr = 0;
        int right_ptr = 0;
        vector<int> ans;
        while (left_ptr < left.size() || right_ptr < right.size())
        {
            if (left[left_ptr] < right[right_ptr])
            {
                ans.push_back(left[left_ptr]);
                left_ptr++;
            }
            else
            {
                ans.push_back(right[right_ptr]);
                right_ptr++;
            }
        }

        while (right_ptr < right.size())
        {
            ans.push_back(right[right_ptr]);
            right_ptr++;
        }
        while (left_ptr < left.size())
        {
            ans.push_back(left[left_ptr]);
            left_ptr++;
        }
        return ans;
    }

public:
    vector<int> mergeSort(int low, int high, vector<int> &arr)
    {

        // base case
        if (low == high)
        {
           return {arr[low]};
        }

        int mid = (low + high) / 2;
        vector<int> left = mergeSort(low, mid, arr);
        vector<int> right = mergeSort(mid + 1, high, arr);
        vector<int> merged = mergeSortedArrays(left, right);
        return merged;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {2, 3, 5, 1, 4};
    vector<int> ans = s.mergeSort(0, arr.size() - 1, arr);
    for (const auto el : ans)
        cout << el << ",";
    cout << "\n";
    return 0;
}