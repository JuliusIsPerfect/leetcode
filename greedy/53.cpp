#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int res = nums[0], tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp += nums[i];
            if (tmp > res) res = tmp;
            if (tmp < 0) {
                tmp = 0;
                continue;
            }
        }
        return res;
    }
};