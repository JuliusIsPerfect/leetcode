#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> map;
        int res = 0, cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (map.find(s[i]) == map.end()) {
                map.insert({s[i], i});
                ++cur;
                res = (cur > res) ? cur : res;
            }
            else {
                cur = i - map[s[i]];
                for (auto iter = map.begin(); iter != map.end();) {
                    if (iter->second < map[s[i]]) {
                        map.erase(iter++);
                    }
                    else {
                        ++iter;
                    }
                }
                map[s[i]] = i;
            }
        }
        return res;
    }
};

int main() {
    std::string s{"tmmzuxt"};
    Solution slt;
    int res = slt.lengthOfLongestSubstring(s);
    std::cin.get();
}