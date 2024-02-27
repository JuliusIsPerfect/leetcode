#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> pth;
    bool used[8] = {false};

    void backtracking(std::vector<int>& nums) {
        if (pth.size() == nums.size()) {
            result.emplace_back(pth);
            return;
        }

        bool flag[21] = {false};
        for (int i = 0; i < nums.size(); ++i) {
            if (flag[nums[i] + 10]) continue;
            if (!used[i]) {
                flag[nums[i] + 10] = true;
                used[i] = true;
                pth.emplace_back(nums[i]);
                backtracking(nums);
                used[i] = false;
                pth.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        if (nums.size() == 1) { return {nums}; }
        std::sort(nums.begin(), nums.end());
        backtracking(nums);
        return result;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 2};
    Solution slt;
    slt.permuteUnique(nums);
    std::cin.get();
}