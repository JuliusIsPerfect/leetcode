#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int res = 0;
        std::vector<int> path{1, 1};
        for (int i = 2; i <= n; ++i) {
            path.emplace_back(path[i - 1] + path[i - 2]);
        }
        return path[n];
    }
};