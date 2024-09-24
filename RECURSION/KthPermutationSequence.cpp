#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void getAllPermutations(int size, unordered_map<int, bool> &isTaken, int n, int &k, vector<int> &temp,string &ans)
    {
        if (size == n)
        {
            k--;
            if(k== 0){
                for(const auto el : temp){
                    ans.append(to_string(el));
                }
                return;
            }
            return;
        }
        if(k == 0)
            return;
        for (int i = 1; i <= n; i++)
        {
            if (!isTaken[i])
            {
                isTaken[i] = true;
                temp.push_back(i);
                getAllPermutations(size + 1, isTaken, n, k, temp,ans);
                isTaken[i] = false;
                temp.pop_back();
            }
        }
    }
    string getPermutation(int n, int k)
    {
        string ans;
        vector<int>temp;
        unordered_map<int,bool> isTaken;
        getAllPermutations(0,isTaken,n,k,temp,ans);
        return ans;
    }
};
int main()
{
    Solution s;
    cout<<s.getPermutation(3,1);

    return 0;
}