#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int> > path(m, std::vector<int>(n, 0));
        if (n == 1 || m == 1) { return 1; }
        path[0][0] = 1;
        path[0][1] = 1;
        path[1][0] = 1;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x == 0 && y ==0) continue;
                if (x == 0) {
                    path[x][y] = path[x][y - 1];
                    continue;
                }
                else if (y == 0) {
                    path[x][y] = path[x - 1][y];
                    continue;
                }
                path[x][y] = path[x - 1][y] + path[x][y - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};

int main() {
    int m = 1, n = 2;
    Solution slt;
    int res = slt.uniquePaths(m, n);

    std::cin.get();
}