#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPlace(char number, vector<vector<char>> &board, int row, int col)
    {
        // check horizontally
        bool flag = true;
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == number)
            {
                flag = false;
                break;
            };
        }
        // check vertically
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == number)
            {
                flag = false;
                break;
            }
        }
        // check sector wise
        int rowIndex = row / 3;
        int colIndex = col / 3;
        for (int i = rowIndex * 3; i < (rowIndex * 3) - 1; i++)
        {
            for (int j = colIndex * 3; j < (colIndex * 3) - 1; j++)
            {
                if (board[i][j] == number)
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    bool solveSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;
                for (char number = '1'; number <= '9'; number++)
                {
                    if (canPlace(number, board, row, col))
                    {
                        board[row][col] = number;
                        if (solveSudoku(board))
                            return true;
                        else
                            board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

};
int main()
{
    return 0;
}