#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        int res = 0;
        std::vector<std::vector<int>> dp(l1 + 1, std::vector<int>(l2 + 1, 0));

        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = std::max(std::max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                res = std::max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main() {
    std::string text1{"abcde"};
    std::string text2{"ace"};
    Solution slt;
    int res = slt.longestCommonSubsequence(text1, text2);
    std::cin.get();
}

