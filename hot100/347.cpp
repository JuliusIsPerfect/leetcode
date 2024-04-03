#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        std::vector<int> res;

        auto cmp = [](std::pair<int, int>& A, std::pair<int, int>& B) {
          return A.second < B.second;
        };

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(cmp)>
            que(cmp);

        for (auto &i : nums) {
            ++map[i];
        }

        for (auto &pair : map) {
            que.push(pair);
        }

        while (k--) {
            res.push_back(que.top().first);
            que.pop();
        }

        return res;
    }
};