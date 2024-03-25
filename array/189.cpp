#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[(i + k) % n] = nums[i];
        }
        nums = res;
    }
};