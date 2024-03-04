#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> res{0, 0, cost[0] <= cost[1] ? cost[0] : cost[1]};
        for (int i = 3; i <= cost.size(); ++i) {
          res.emplace_back(res[i - 2] + cost[i - 2] <= res[i - 1] + cost[i - 1]
                               ? res[i - 2] + cost[i - 2]
                               : res[i - 1] + cost[i - 1]);
        }

        return res.back();
    }
};

int main() {
    std::vector<int> cost{10,15,20};
    Solution slt;
    int res = slt.minCostClimbingStairs(cost);

    std::cin.get();
}