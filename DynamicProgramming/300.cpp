#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return (nums[0] < nums[1]) ? 2 : 1;
        }
        
        int res = 0;
        std::vector<int> dp(n, 1);
        dp[0] = 1;
        dp[1] = (nums[0] < nums[1]) ? 2 : 1;

        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);
            }
            if (dp[i] > res) res = dp[i];
        }

        return res;
    }
};