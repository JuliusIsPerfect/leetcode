#include <iostream>
#include <ostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> Queen;

    bool isValid(int row, int col, int& n) {
        for (int i = 0; i < row; ++i) {
            if (Queen[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (Queen[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (Queen[i][j] == 'Q') return false;
        }
        return true;
    }

    void dfs(int& n, int num) {
        if (num == n) {
            result.emplace_back(Queen);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (num > 0) {
                if (isValid(num, i, n)) {
                    Queen[num][i] = 'Q';
                    dfs(n, num + 1);
                    Queen[num][i] = '.';
                }
            }
            else {
                Queen[num][i] = 'Q';
                dfs(n, num + 1);
                Queen[num][i] = '.';
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        Queen = std::vector<std::string>(n, std::string(n, '.'));
        dfs(n, 0);
        return result;
    }
};

int main() {
    std::string s(5, '.');
    std::cout << "s: " << s <<std::endl;
    s.insert(s.begin(), 'Q');
    std::cout << "s: " << s <<std::endl;
    std::cin.get();
}