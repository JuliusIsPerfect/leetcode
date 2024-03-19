#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      if (n == 1) {
        return false;
      }

      std::vector<int> dp(10001, 0);

      sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2 != 0) {
        return false;
      }

      int target = sum / 2;
      dp[0] = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = target; j >= nums[i]; --j) {
          dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
        } 
      }
      if (dp[target] == target) {
        return true;
      }
      return false;
    }
};

int main() {
  std::vector<int> nums = {2,2,1,1};
  Solution slt;
  bool res = slt.canPartition(nums);
  std::cin.get();
}