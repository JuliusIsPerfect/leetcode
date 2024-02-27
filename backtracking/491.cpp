#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> pth;
    
    void dfs(std::vector<int>& nums, int idx) {
        if (pth.size() >= 2) {
            result.push_back(pth);
            // return;
        }
        std::vector<bool> used = std::vector<bool>(200);
        for (int i = idx; i < nums.size(); i++) {
            if (used[nums[i] + 100] == 1 || (!pth.empty() && nums[i] < pth.back())) continue;
            used[nums[i] + 100] = 1;
            pth.push_back(nums[i]);
            dfs(nums, i + 1);
            pth.pop_back();
        }
    }

    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};