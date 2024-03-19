#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // int sum = 0;
        // sum = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};

int main() {
    std::vector<int> nums{1,2,3,1};
    Solution slt;
    int res = slt.rob(nums);
    std::cin.get();
}