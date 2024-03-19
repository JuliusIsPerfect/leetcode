#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return std::max(nums[0], nums[1]);
        }
        if (n == 3) {
            return std::max(std::max(nums[0], nums[1]), nums[2]);
        }

        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        std::vector<int> dp2(nums.size(), 0);
        dp2[1] = nums[1];
        dp2[2] = std::max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i) {
            dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return std::max(dp[n - 2], dp2[n - 1]);
    }
};