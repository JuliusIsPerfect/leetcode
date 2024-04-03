#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(target - nums[i]) != map.end()) {
                if (map[target - nums[i]] != i)
                    return {map[target - nums[i]], i};
            }
            if (map.find(nums[i]) == map.end()) {
                map.insert({nums[i], i});
            }
        }

        return {};
    }
};