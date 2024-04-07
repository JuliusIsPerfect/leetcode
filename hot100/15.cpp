#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> res{};

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int right = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            right = nums.size() - 1;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                while (j < right && nums[i] + nums[j] + nums[right] > 0) {
                    --right;
                }

                if (j == right) {
                    break;
                }

                if (nums[i] + nums[j] + nums[right] == 0) {
                    res.push_back({nums[i], nums[j], nums[right]});
                    // break;
                }
            }
        }

        return res;
    }
};