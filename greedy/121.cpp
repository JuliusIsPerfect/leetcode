#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int low = INT_MAX, res = 0;

        for (int i = 0; i < prices.size(); ++i) {
            low = std::min(low, prices[i]);
            res = std::max(res, prices[i] - low);
        }

        return res;
    }
};