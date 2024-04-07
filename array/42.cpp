#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n == 1) {
            return 0;
        }
        std::vector<int> leftMAX(n, 0);
        std::vector<int> rightMAX(n, 0);
        leftMAX[0] = height[0];
        rightMAX[0] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            leftMAX[i] = (leftMAX[i - 1] > height[i]) ? leftMAX[i - 1] : height[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            rightMAX[i] = (rightMAX[i + 1] > height[i]) ? rightMAX[i + 1] : height[i];
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res +=  std::min(leftMAX[i], rightMAX[i]);
        }

        return res;
    }
};