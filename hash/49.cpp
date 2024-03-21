#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        if (strs.size() == 0 || strs.size() == 1) {
            return {strs};
        }

        std::unordered_set<std::string> set;
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::string temp;
        for (auto &s : strs) {
            temp = s;
            std::sort(temp.begin(), temp.end());
            if (map.find(temp) == map.end()) {
                map.insert({temp, {s}});
            }
            else map[temp].emplace_back(s);
            // set.insert(s);
        }

        std::vector<std::vector<std::string>> res;
        for (auto &iter : map) {
            res.emplace_back(iter.second);
        }
        return res;
    }
};