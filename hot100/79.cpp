#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> used;
    int len;

    bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y) {
        if (idx == len - 1) {
            return true;
        }

        if (x - 1 >= 0 && !used[x - 1][y] && board[x - 1][y] == word[idx + 1]) {
            used[x - 1][y] = true;
            if (dfs(board, word, idx + 1, x - 1, y)) {
                return true;
            }
            used[x - 1][y] = false;
        }

        if (x + 1 < board.size() && !used[x + 1][y] && board[x + 1][y] == word[idx + 1]) {
            used[x + 1][y] = true;
            if (dfs(board, word, idx + 1, x + 1, y)) {
                return true;
            }
            used[x + 1][y] = false;
        }

        if (y - 1 >= 0 && !used[x][y - 1] && board[x][y - 1] == word[idx + 1]) {
            used[x][y - 1] = true;
            if (dfs(board, word, idx + 1, x, y - 1)) {
                return true;
            }
            used[x][y - 1] = false;
        }

        if (y + 1 < board[0].size() && !used[x][y + 1] && board[x][y + 1] == word[idx + 1]) {
            used[x][y + 1] = true;
            if (dfs(board, word, idx + 1, x, y + 1)) {
                return true;
            }
            used[x][y + 1] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        len = word.size();
        auto find = false;
        used = vector<vector<bool>>(board.size(),
                                    vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    find = dfs(board, word, 0, i, j);
                    used[i][j] = false;
                    if (find) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};