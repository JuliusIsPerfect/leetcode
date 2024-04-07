#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }

        vector<vector<bool>> dp(n, vector<bool>(n, true));
        int begin = 0, lenmax = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                if (dp[i][j]) {
                    if (j - i + 1 > lenmax) {
                        lenmax = j - i + 1;
                        begin = i;
                    }
                }
            }
        }

        return s.substr(begin, lenmax);
    }
};