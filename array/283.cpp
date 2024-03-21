#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[cur] = nums[i];
                ++cur;
            }
        }
        for (int i = cur + 1; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

int main() {
    std::vector<int> nums{1,0};
    Solution slt;
    slt.moveZeroes(nums);

    std::cin.get();
}