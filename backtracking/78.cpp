#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> pth;
    std::vector<bool> used;

    void dfs(std::vector<int>& nums, int idx){
        if (idx >= nums.size()) {
            result.push_back(pth);
            return;
        }

        pth.push_back(nums[idx]);
        dfs(nums, idx + 1);
        pth.pop_back();
        dfs(nums, idx + 1);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        used = std::vector<bool>(nums.size());
        dfs(nums, 0);
        return result;
    }
};

int main() {
    std::vector<int> nums = {1,2,3};
    Solution slt;
    slt.subsets(nums);
    std::cin.get();
}