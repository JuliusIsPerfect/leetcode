#include <limits.h>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

class Solution {
 public:
  int largestSumAfterKNegations(std::vector<int>& nums, int k) {
    int sum = 0, minpos = INT_MAX;
    std::multiset<int> set;

    for (auto& it : nums) {
      if (it < 0) {
        set.insert(it);
      } else {
        sum += it;
        if (it < minpos) minpos = it;
      }
    }

    if (set.empty()) {
        if (k % 2 == 0) {}
        else sum -= 2 * minpos;
    }

    else {
        auto it = set.begin();
        if (k <= set.size()) {
            while (k--) {
                sum += -(*it);
                it++;
            }
            for (; it != set.end(); it++) {
                sum += *it;
            }
        } else {
            for (; it != set.end(); it++) {
                sum += -(*it);
            }
            if ((k - set.size()) % 2 == 0) {
            } else
                sum = (*std::prev(set.end()) > -minpos) ? sum + 2 * *std::prev(set.end()) : sum - 2 * minpos;
        }
    }

    return sum;
  }
};

int main() {
  std::vector<int> nums{5,6,9,-3,3};
  int k = 2;
  Solution slt;
  int sum = slt.largestSumAfterKNegations(nums, k);

  std::cin.get();
}