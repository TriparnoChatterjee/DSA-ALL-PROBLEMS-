#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int pos = 0;
        int lastEl = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != lastEl)
            {
                pos++;
                nums[pos] = nums[i];
                lastEl = nums[i];
            }
        }
        return pos + 1;
    }
};
int main()
{
    /*
        Keep a counter to maintain only unique elements 
        now start iteration from 1st index as the 0th index will always be unique
     */
    return 0;
}