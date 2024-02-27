#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> pth;
    bool flag[6];

    void backtracking(std::vector<int>& nums) {
        if (pth.size() == nums.size()) {
            result.emplace_back(pth);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!flag[i]) {
                flag[i] = true;
                pth.emplace_back(nums[i]);
                backtracking(nums);
                flag[i] = false;
                pth.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        if (nums.size() == 1) { return {nums}; }
        backtracking(nums);
        return result;
    }
};

int main() {
    std::vector<int> nums = {1,2,3};
    Solution slt;
    slt.permute(nums);
    std::cin.get();
}