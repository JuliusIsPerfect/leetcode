#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> pq;
        for (int i = 0; i < stones.size(); ++i) {
            pq.push(stones[i]);
        }
        int x, y;
        while (pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if (x == y) {
                continue;
            }
            pq.push((x < y) ? y - x : x - y);
        }
        if (pq.size() == 1) {
            return pq.top();
        }
        return 0;
    }
};

int main() {
    std::vector<int> stones{1, 3};
    Solution slt;
    int res = slt.lastStoneWeight(stones);
    std::cin.get();
}