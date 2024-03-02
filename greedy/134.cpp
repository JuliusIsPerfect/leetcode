#include <iostream>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_sum = 0, cur_sum = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            cur_sum += gas[i] - cost[i];
            total_sum = gas[i] - cost[i];
            if (cur_sum < 0) {
                cur_sum = 0;
                start = i + 1;
            }
        }
        if (total_sum < 0) return -1;

        return start;
    }
};

int main() {
    std::vector<int> gas{1,2,3,4,5}, cost{3,4,5,1,2};
    Solution slt;
    int ans = slt.canCompleteCircuit(gas, cost);

    std::cin.get();
}