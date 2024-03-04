#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        int res = 1;
        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) { return a[1] < b[1];} 
            return a[0] < b[0];
        };

        std::sort(points.begin(), points.end(), cmp);
        int l = points[0][0], r = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= r) {
                if (points[i][1] < r) r = points[i][1];
            }
            else {
                res++;
                l = points[i][0];
                r = points[i][1];
            }

        }

        return res;
    }
};

int main() {
    std::vector<std::vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    Solution slt;
    int res = slt.findMinArrowShots(points);

    std::cin.get();
}