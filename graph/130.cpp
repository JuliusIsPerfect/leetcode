#include <iostream>
#include <vector>

class Solution {
public:
    int m, n;
    void dfs(int x, int y, std::vector<std::vector<char>>& board) {
        board[x][y] = 'A';
        if (x > 0 && board[x - 1][y] == 'O')
            dfs(x - 1, y, board);
        if (x < m - 1 && board[x + 1][y] == 'O')
            dfs(x + 1, y, board);
        if (y > 0 && board[x][y - 1] == 'O')
            dfs(x, y - 1, board);
        if (y < n - 1 && board[x][y + 1] == 'O')
            dfs(x, y + 1, board);
    }

    void solve(std::vector<std::vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // 第0行
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                dfs(0, i, board);
            }
        }
        // 第m - 1行
        for (int i = 0; i < n; ++i) {
            if (board[m - 1][i] == 'O') {
                dfs(m - 1, i, board);
            }
        }
        // 第0列
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
        }
        // 第n - 1列
        for (int i = 0; i < m; ++i) {
            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1, board);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};