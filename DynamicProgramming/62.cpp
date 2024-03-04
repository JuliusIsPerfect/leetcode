#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int> > path(m, std::vector<int>(n, 0));
        path[0][1] = 1;
        path[1][0] = 1;
        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                path[m][n] = path[m - 1][n] + path[m][n - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 7;
    Solution slt;
    int res = slt.uniquePaths(m, n);

    std::cin.get();
}