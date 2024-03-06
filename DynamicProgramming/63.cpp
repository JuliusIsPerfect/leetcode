#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<int> > path(m, std::vector<int>(n, 0));
        path[0][0] = 1;
        if (m == 1) {
            for (auto& it : obstacleGrid[0]) {
                if (it == 1) return 0;
            }
            return 1;
        }
        if (n == 1) {
            for (auto& it : obstacleGrid) {
                if (it[0] == 1) return 0;
            }
            return 1;
        }
        path[0][1] = 1;
        path[1][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] != 1) path[i][0] = 1;
            else break;
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] != 1) path[0][i] = 1;
            else break;
        }
        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                if (obstacleGrid[x][y] != 1) {
                    if (obstacleGrid[x - 1][y] == 1 && obstacleGrid[x][y - 1] == 1) continue;
                    if (obstacleGrid[x - 1][y] == 1) {
                        path[x][y] = path[x][y - 1];
                        continue;
                    }
                    else if (obstacleGrid[x][y - 1] == 1) {
                        path[x][y] = path[x - 1][y];
                        continue;
                    }
                    else {
                        path[x][y] = path[x - 1][y] + path[x][y - 1];
                        continue;
                    }
                }
            }
        }
        return path[m - 1][n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> obstacleGrid{{0,1}};
    Solution slt;
    slt.uniquePathsWithObstacles(obstacleGrid);

    
}