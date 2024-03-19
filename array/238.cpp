#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> l;
        std::vector<int> r(nums.size());
        std::vector<int> ans;
        l.emplace_back(1);
        r[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            l.emplace_back(l[i - 1] * nums[i - 1]);
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            r[i] = r[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < nums.size(); ++i) {
            ans.emplace_back(l[i] * r[i]);
        }

        return ans;
    }
};

int main() {

    std::cin.get();
}