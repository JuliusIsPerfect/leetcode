#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n + 4, 0);
        dp[1] = 1, dp[2] = 1, dp[3] = 2, dp[4] = 4;
        if (n <= 4) return dp[n];
        for (int i = 5; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                dp[i] = std::max(dp[i], std::max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};

int main() {
    int n;
    std::cin >> n;
    Solution slt;
    slt.integerBreak(n);

}