#include <iostream>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] == k) {
                return 1;
            }
            return 0;
        }
        std::vector<int> presum(n);
        presum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (presum[i] == k) ++res;
            for (int j = 0; j < i; ++j) {
                if (presum[i] - presum[j] == k) ++res;
            }
        }

        return res;
    }
};