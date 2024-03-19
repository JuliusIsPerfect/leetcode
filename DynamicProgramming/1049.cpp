#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int n = stones.size();
        if (n == 1) {
            return stones[0];
        }
        std::vector<int> dp(15001, 0);
        int sum = 0;
        sum = std::accumulate(stones.begin(), stones.end(), 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = sum / 2; j >= stones[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return (sum - dp[sum / 2]) - (dp[sum / 2]);
    }
};