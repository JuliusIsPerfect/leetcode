#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> tneed;
        std::unordered_map<char, int> cur;
        int charsum = 0, cursum = 0;
        for (auto &c : t) {
            // if (tneed.find(c) == tneed.end()) tneed[c] = 1;
            // else ++tneed[c];
            ++tneed[c];
            // cur[c] = 0;
            ++charsum;
        }
        
        std::string res;
        int left = 0;  // 滑动窗口左端
        for (int i = 0; i < s.size(); ++i) {
            if (cur[s[i]] < tneed[s[i]]) ++cursum;
            ++cur[s[i]];

            if (charsum == cursum) {  // 当前窗口内已经包含的字符数等于所需字符数
                while (cur[s[left]] > tneed[s[left]]) {  // 移除多余的字符 s[left]，窗口左端右移
                    --cur[s[left]];
                    // --cursum;
                    ++left;
                }

                if (res.empty() || res.size() > i - left + 1) {
                    res = s.substr(left, i - left + 1);
                }

                // 此时窗口左端刚好满足窗口内字符个数符合要求
                // 窗口左端右移一位，已经涵盖的字符减少 1 个
                --cur[s[left]];
                ++left;
                --cursum;
            }
        }

        return res;
    }
};