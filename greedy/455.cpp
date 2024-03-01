#include <iostream>
#include <vector>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int sum = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                ++sum;
                j++;
                i++;
            }
            else j++;
        }

        return sum;
    }
};
