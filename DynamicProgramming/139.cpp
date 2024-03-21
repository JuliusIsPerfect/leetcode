#include <limits.h>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordset;
        // int minlen = INT_MAX;
        for (auto &word : wordDict) {
            wordset.insert(word);
            // minlen = (word.size() < minlen) ? word.size() : minlen;
        }

        int lens = s.size();
        // int lenD = wordDict.size();
        std::string temp;
        std::vector<int> dp(lens + 1, false);
        dp[0] = true;

        for (int i = 1; i <= lens; ++i) {
            for (int j = 0; j < i; ++j) {
                // if (i - j < minlen) break;
                temp = s.substr(j, i - j);
                if (dp[j] && wordset.find(temp) != wordset.end()) {
                    dp[i] = true;
                }
            }
        }

        return dp[lens];
    }
};