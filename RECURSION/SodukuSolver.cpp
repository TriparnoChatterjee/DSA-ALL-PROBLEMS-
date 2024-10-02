#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlace(char number, vector<vector<char>>& board, int row, int col) {
        // check horizontally
        bool flag = true;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == number) {
                flag = false;
                break;
            };
        }
        // check vertically
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == number) {
                flag = false;
                break;
            }
        }
        // check sector wise
        int rowIndex = row / 3;
        int colIndex = col / 3;
        for (int i = rowIndex * 3; i < (rowIndex * 3) + 3; i++) {
            for (int j = colIndex * 3; j < (colIndex * 3) + 3; j++) {
                if (board[i][j] == number) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.')
                    continue;
                for (char number = '1'; number <= '9'; number++) {
                    if (canPlace(number, board, row, col)) {
                        board[row][col] = number;
                        if (solve(board))
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
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
int main()
{
    vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution s;
    s.solveSudoku(board);
    return 0;
}