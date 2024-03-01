#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        std::unordered_map<int, int> cash;
        cash[5] = 0;
        cash[10] = 0;
        cash[20] = 0;
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) cash[5] += 1;
            else {
                if (bills[i] == 10) {
                    if (cash[5] == 0) return false;
                    else {
                        cash[5] -= 1;
                        cash[10] += 1;
                        continue;
                    }
                }
                else {
                    if (cash[5] >= 1 && cash[10] >= 1) {
                        cash[5] -= 1;
                        cash[10] -= 1;
                        cash[20] += 1;
                        continue;
                    }
                    else if (cash[5] >= 3) {
                        cash[5] -= 3;
                        cash[20] += 1;
                        continue;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};