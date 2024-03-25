#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = (r - l) * std::min(height[l], height[r]);
        int next = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                ++l;
                next = (r - l) * std::min(height[l], height[r]);
                res = (next > res) ? next : res;
                continue;
            }
            if (height[l] > height[r]) {
                --r;
                next = (r - l) * std::min(height[l], height[r]);
                res = (next > res) ? next : res;
                continue;
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution slt;
    int res = slt.maxArea(height);
    std::cin.get();
}