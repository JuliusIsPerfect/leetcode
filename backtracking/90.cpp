#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> pth;

    void dfs(std::vector<int>& nums, int idx){
        if (idx >= nums.size()) {
            result.push_back(pth);
            return;
        }

        pth.push_back(nums[idx]);
        dfs(nums, idx + 1);
        pth.pop_back();
        idx++;
        if (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            while(idx < nums.size() && nums[idx] == nums[idx - 1]) {
                    idx++;
            }
        }
        dfs(nums, idx);
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return result;
    }
};