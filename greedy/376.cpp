#include <iostream>
#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        int num = 0;
        int flag = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1] && flag != 1) {
                num++;
                flag = 1;
            }
            if (nums[i] < nums[i - 1] && flag != 2) {
                num++;
                flag = 2;
            }
        }
        return num + 1; // 返回最长子序列的长度 = 单调性变化处 + 1
    }
};