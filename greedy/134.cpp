#include <iostream>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int res = 0, sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum = 0;
            if (gas[i] >= cost[i]) {
                for (int j = i + 1; ;++j) {
                    if (j == gas.size()) {
                        j = 0;
                        continue;
                    }
                    if (j == i) return i;
                    if (gas[j] >= cost[j]) {
                        sum = gas[j] - cost[j];
                        continue;
                    }
                }
            }
            
        }
        return -1;
    }
};