#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> res;
        std::vector<int> last(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = std::max(end, last[s[i] - 'a']);
            if (i == end) {
                res.emplace_back(end - start + 1);
                start = end;
            }
        }

        return res;
    }
};

