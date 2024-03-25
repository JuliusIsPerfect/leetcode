#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end());
        int l = intervals[0][0], r = intervals[0][1];
        std::vector<int> cur{l, r};
        std::vector<std::vector<int>> res{cur};
        int cnt = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res[cnt][1]) {
                if (intervals[i][1] > res[cnt][1]) {
                    res[cnt][1] = intervals[i][1];
                }
            }
            else {
                cur = {intervals[i][0], intervals[i][1]};
                res.emplace_back(cur);
                ++cnt;
            }
        }
        return res;
    }
};