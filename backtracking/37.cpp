#include <iostream>
#include <vector>

class Solution {
public:
    bool isValid(int row, int col, std::vector<std::vector<char>>& board, int& val){
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == '0' + val) return false;
        }
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == '0' + val) return false;
        }
        for (int i = (row/3) * 3; i < (row/3) * 3 + 3; ++i) {
            for (int j = (col/3) * 3; j < (col/3) * 3 + 3; ++j)
                if (board[i][j] == '0' + val) return false;
        }
        return true;
    }

    bool dfs(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) {
                        if (isValid(i, j, board, k)) {
                            board[i][j] = '0' + k;
                            if (dfs(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(std::vector<std::vector<char>>& board) {
        dfs(board);
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution slt;
    slt.solveSudoku(board);

    std::cin.get();
}