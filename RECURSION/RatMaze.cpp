#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     bool isPossible(int row, int col, vector<vector<int>> &mat, vector<vector<bool>> &vis, int n)
//     {
//         if (row >= 0 and row < n and col >= 0 and col < n and !vis[row][col] and mat[row][col] != 0)
//             return true;
//         else
//             return false;
//     }
//     void solve(int row, int col, string &temp, vector<string> &ans, int n, vector<vector<int>> &mat, vector<vector<bool>> &vis)
//     {
//         if (row == n - 1 and col == n - 1)
//         {
//             ans.push_back(temp);
//             return;
//         }

//         vis[row][col] = true;
//         // up
//         if (isPossible(row - 1, col, mat, vis, n))
//         {
//             temp.push_back('U');
//             // vis[row][col] = true;
//             solve(row - 1, col, temp, ans, n, mat, vis);
//             // vis[row][col] = false;
//             temp.pop_back();
//         }

//         // down
//         if (isPossible(row + 1, col, mat, vis, n))
//         {
//             temp.push_back('D');
//             // vis[row][col] = true;
//             solve(row + 1, col, temp, ans, n, mat, vis);
//             // vis[row][col] = false;
//             temp.pop_back();
//         }

//         // left
//         if (isPossible(row, col - 1, mat, vis, n))
//         {
//             temp.push_back('L');
//             // vis[row][col] = true;
//             solve(row, col - 1, temp, ans, n, mat, vis);
//             // vis[row][col] = false;
//             temp.pop_back();
//         }

//         // right
//         if (isPossible(row, col + 1, mat, vis, n))
//         {
//             temp.push_back('R');
//             // vis[row][col] = true;
//             solve(row, col + 1, temp, ans, n, mat, vis);
//             // vis[row][col] = false;
//             temp.pop_back();
//         }
//         vis[row][col] = false;
//         return;
//     }
//     vector<string> findPath(vector<vector<int>> &mat)
//     {
//         vector<string> ans;
//         string temp;
//         int n = mat.size();
//          if(mat[0][0] == 0 || mat[n-1][n-1] == 0)
//           return {};
//         vector<vector<bool>> vis(n, vector<bool>(n, false));
//         solve(0, 0, temp, ans, n, mat, vis);
//         return ans;
//     }
// };

    class Solution
    {
    public:
        int di[4] = {1,0,0,-1};
        int dj[4] = {0,-1,1,0};
        string dir = "DLRU";
        bool isPossible(int row, int col, vector<vector<int>> &mat, vector<vector<bool>> &vis, int n)
        {
            if (row >= 0 and row < n and col >= 0 and col < n and !vis[row][col] and mat[row][col] != 0)
                return true;
            else
                return false;
        }
        void solve(int row, int col, string &temp, vector<string> &ans, int n, vector<vector<int>> &mat, vector<vector<bool>> &vis)
        {
            if (row == n - 1 and col == n - 1)
            {
                ans.push_back(temp);
                return;
            }

            vis[row][col] = true;
            for(int i = 0 ; i<4 ; i++){
                int n_row = row+di[i];
                int n_col = col+dj[i];
                if(isPossible(n_row,n_col,mat,vis,n)){
                    temp.push_back(dir[i]);

                    solve(n_row,n_col,temp,ans,n,mat,vis);

                    temp.pop_back();
                }
            }
            vis[row][col] = false;
            return;
        }
        vector<string> findPath(vector<vector<int>> &mat)
        {
            vector<string> ans;
            string temp;
            int n = mat.size();
            if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
                return {};
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            solve(0, 0, temp, ans, n, mat, vis);
            return ans;
        }
    };
int main()
{
    Solution s;
    vector<vector<int>> mat = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}};
    vector<string> ans = s.findPath(mat);
    for (const auto el : ans)
        cout << el << ",";
    return 0;
}