#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> pre(n, 0), post(n, 0);

        pre[0] = 1;
        post[n - 1] = 1;

        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            post[i] = post[i + 1] * nums[i + 1];
        }

        std::vector<int> answer(n);
        answer[0] = post[0];
        answer[n - 1] = pre[n - 1];
        for (int i = 1; i <= n - 1; ++i) {
            answer[i] = pre[i] * post[i];
        }

        return answer;
    }
};