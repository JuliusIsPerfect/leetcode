#include <iostream>
#include <vector>

class Solution {
 public:
  bool canJump(std::vector<int>& nums) {
    int jump = 0;
    if (nums.size() == 1) return true;
    for (int i = 0; i <= jump; ++i) {
      jump = (i + nums[i] > jump) ? (i + nums[i]) : jump;
      if (jump >= nums.size() - 1) return true;
    //   else if (nums[jump] == 0) return false;
    }
    return false;
  }
};
