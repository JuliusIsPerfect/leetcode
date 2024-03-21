#include <iostream>
#include <vector>

class NumArray {
public:
    std::vector<int> nums_;
    std::vector<int> presum;
    std::vector<int> postsum;
    int sum = 0;

    NumArray(std::vector<int>& nums) {
        nums_ = nums;
        presum = std::vector<int>(nums_.size());
        postsum = std::vector<int>(nums_.size());
        int length = nums_.size();
        presum[0] = 0;
        postsum[length - 1] = 0;
        sum += nums_[0];
        for (int i = 1; i < length; ++i) {
            presum[i] = presum[i - 1] + nums_[i - 1];
            sum += nums_[i];
        }
        for (int i = length - 2; i >= 0; --i) {
            postsum[i] = postsum[i + 1] + nums_[i + 1];
        }
    }

    int sumRange(int left, int right) {
        return sum - presum[left] - postsum[right];
    }
};