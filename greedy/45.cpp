#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
 public:
  int GetMax(std::vector<int>& nums, int l, int r) {
    int max = 0, maxidx = l;
    for (int i = l; i <= r && i < nums.size(); ++i) {
      if (i + nums[i] >= max) {
        max = i + nums[i];
        maxidx = i;
      }
    }
    return maxidx;
  }
  int jump(std::vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int jump = 0, cnt = 0;
    for (int i = 0; i < nums.size();) {
      if (i + nums[i] > jump) {
        jump = i + nums[i];
        if (jump >= nums.size() - 1) {
          return cnt + 1;
        }
        i = GetMax(nums, i + 1, jump);
        cnt++;
      }
    }
    return cnt;
  }
};

int main() {
    std::vector<int> nums = {2,3,1,1,4};
    Solution slt;
    slt.jump(nums);
    std::cin.get();
}