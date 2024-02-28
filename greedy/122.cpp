#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // 可以先购买，然后在 同一天 出售 == 第一天就可以卖掉股票 == 总利润最小就是0
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) sum += prices[i] - prices[i - 1];
        }
        return sum;
    }
};
