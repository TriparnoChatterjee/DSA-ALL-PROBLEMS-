// LINK : https://leetcode.com/problems/combination-sum-ii/
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     void f(int indx, vector<int>& candidates, int target, set<vector<int>>& ans,
//            vector<int>& temp) {
//         if (indx == candidates.size()) {
//             if (target == 0) {
//                 ans.insert(temp);
//             }
//             return;
//         }
//         if (target - candidates[indx] >= 0) {
//             temp.push_back(candidates[indx]);
//             f(indx + 1, candidates, target - candidates[indx], ans, temp);
//             temp.pop_back();
//         }
//         f(indx + 1, candidates, target, ans, temp);
//     }
//     set<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         set<vector<int>> ans;
//         vector<int> temp;
//         f(0, candidates, target, ans, temp);
//         return ans;
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector<int>> temp = combinationSum(candidates, target);
//         vector<vector<int>> ans;
//         for (const auto item : ans) {
//             vector<int>t;
//             for (const auto el : item) {
//                 t.push_back(el);
//             }
//             ans.push_back(t);
//         }
//         return ans;
//     }
// };
/*
    This code will give a tle on large test cases as this includesan overhead of putting it in stack 
 */

class Solution {
public:
    void f(int indx ,vector<int>&arr,vector<vector<int>>&ans,int target,vector<int>&temp){
        if(indx == arr.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = indx ; i<arr.size();i++){
            if(i!=indx and arr[i] == arr[i-1])
                continue;
            if(target-arr[i]>=0){
                temp.push_back(arr[i]);
                f(i+1,arr,ans,target-arr[i],temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,candidates,ans,target,temp);
        return ans;
    }
};
// This code removes the usage of stack
int main()
{
    Solution s;
    vector<int> arr = {2,5,2,1,2};
    sort(arr.begin(),arr.end());
    int target = 5;
    vector<vector<int>> ans = s.combinationSum2(arr, target);
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