#include <iostream>
#include <vector>
#include "algorithm"

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int res = 0;
        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        };
        std::sort(intervals.begin(), intervals.end(), cmp);
        
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][1] < r) {
                res++;
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else if (intervals[i][0] < r && intervals[i][1] > r) {
                res++;
                continue;
            }
            else if (intervals[i][0] >= r) {
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> intervals = 
    {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    Solution slt;
    int res = slt.eraseOverlapIntervals(intervals);
    std::cin.get();
}