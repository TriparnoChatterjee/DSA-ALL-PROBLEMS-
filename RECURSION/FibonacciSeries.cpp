#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // memoization function
    int memo(int n, vector<int> &dp)
    {
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = memo(n - 1, dp) + memo(n - 2, dp);
    }
    int fib(int n)
    {
        // if(n==0)
        //     return 0;
        // if(n==1 || n== 2)
        //     return 1;
        // return fib(n-1)+fib(n-2);
        vector<int> dp(n + 1);
        if (n >= 0)
            dp[0] = 0;
        if (n >= 1)
            dp[1] = 1;
        if (n >= 2)
            dp[2] = 1;
        if (n < 3)
            return dp[n];
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        // return memo(n,dp);
    }
};
int main()
{
    Solution s;
    cout << s.fib(5);
    return 0;
}