#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int ls = s.size(), lp = p.size();
        std::map<char, int> window, pmap;

        std::vector<int> res{};
        for (int i = 0; i < lp; ++i) {
            if (pmap.find(p[i]) == pmap.end()) {
                pmap.insert({p[i], 1});
            }
            else ++pmap[p[i]];
        }
        // s = "cbaebabacd", p = "abc"
        int cur = 0;
        for (int i = 0; i < ls; ++i) {
            if (pmap.find(s[i]) == pmap.end()) {
                for (int j = i - cur; j < i; ++j) {
                    --window[s[j]];
                }
                cur = 0;
                continue;
            }
            else {
                if (window.find(s[i]) == window.end()) {
                    window.insert({s[i], 1});
                    // ++cur;
                }
                else {
                    ++window[s[i]];
                }

                if (window[s[i]] <= pmap[s[i]]) {
                    ++cur;
                    if (cur == lp) {
                        res.emplace_back(i + 1 - cur);
                        --window[s[i - cur + 1]];
                        cur -= 1;
                    }
                }
                else {
                    int j;
                    for (j = i - cur; j < i; ++j) {
                        --window[s[j]];
                        if (s[j] == s[i]) {
                            break;
                        }
                    }
                    cur -= j - i + cur;
                }
            }
        }
        return res;
    }
};

int main() {
    std::string s = "abaacbabc", p = "abc";
    Solution slt;
    auto res = slt.findAnagrams(s, p);
    std::cin.get();
}