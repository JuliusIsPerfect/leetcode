#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return (nums[0] < nums[1]) ? 2 : 1;
        }

        int flag = 0;
        int l = 1;
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                flag = 1;
                ++l;
                res = (l > res) ? l : res;
            }
            else {
                flag = 1;
                l = 1;
            }
        }
        return res;
    }
};