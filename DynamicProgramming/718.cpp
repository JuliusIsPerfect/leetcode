#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int res = 0;
        std::vector<std::vector<int>> dp(l1 + 1, std::vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (nums1[i] == nums2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                res = std::max(res, dp[i][j]);
            }
        }
        return res;
    }
};