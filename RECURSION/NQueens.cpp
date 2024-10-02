#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPlace(vector<string> &temp, int row, int col, int n)
    {
        // check vertically
        for (int i = 0; i < n; i++)
        {
            if (temp[i][col] == 'Q')
                return false;
        }
        // check diagonals upper left diagonal
        int dup_row = row;
        int dup_col = col;
        while (dup_row >= 0 && dup_col >= 0)
        {
            if (temp[dup_row][dup_col] == 'Q')
                return false;
            dup_row--;
            dup_col--;
        }
        // check upper right diagonal
        dup_row = row;
        dup_col = col;
        while (dup_row >= 0 and dup_col < n)
        {
            if (temp[dup_row][dup_col] == 'Q')
                return false;
            dup_row--;
            dup_col++;
        }
        // check lower left diagonal
        dup_row = row;
        dup_col = col;
        while (dup_row < n and dup_col >= 0)
        {
            if (temp[dup_row][dup_col] == 'Q')
                return false;
            dup_row++;
            dup_col--;
        }

        // check lower right diagonal
        dup_row = row;
        dup_col = col;
        while (dup_row < n and dup_col < n)
        {
            if (temp[dup_row][dup_col] == 'Q')
                return false;
            dup_row++;
            dup_col++;
        }
        return true;
    }
    void solve(int row, int n, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (row == n)
        {
            ans.push_back(temp);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            //            string rowExpr(n, '.');
            if (canPlace(temp, row, col, n))
            {
                temp[row][col] = 'Q';
                solve(row + 1, n, temp, ans);
                temp[row][col] = '.';
            }
            //            temp.push_back(rowExpr);
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string board(n, '.');
        vector<string> temp(n, board);
        solve(0, n, temp, ans);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(4);
    for (const auto item : ans)
    {
        for (const auto el : item)
        {
            cout << el << "\n";
        }
        cout << "\n\n";
    }
    return 0;
}