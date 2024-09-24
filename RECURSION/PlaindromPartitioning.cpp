#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool isPalin(string s){
        string temp = s;
        reverse(temp.begin(),temp.end());
        return temp == s;
    }
    void f(int indx,vector<vector<string>>&ans,string s, vector<string>&temp){
        if(indx == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = indx;i<s.size();i++){
            string substring = s.substr(indx,i-indx+1);
            if(isPalin(substring)){
                temp.push_back(substring);
                f(i+1,ans,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0,ans,s,temp);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<string>>ans = s.partition("aab");
    for(const auto item : ans){
        for(const auto el : item){
            cout<<el<<",";
        }
        cout<<"\n";
    }
}