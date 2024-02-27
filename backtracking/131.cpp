#include <iostream>

class Solution {
public:
    std::vector<std::string> pth;
    std::vector<std::vector<std::string>> result;

    bool Palindrome(std::string& s) {
        if (s.size() == 0) return true;
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }

    void dfs(std::string s) {
        if (s.size() == 0) {
            result.push_back(pth);
            return;
        }

        for(int i = 1; i <= s.size(); i++){
            auto tmp = s.substr(0, i);
            if(Palindrome(tmp)) {
                pth.push_back(tmp);
                dfs(s.substr(i));
                pth.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        dfs(s);
        return result;
    }
};

int main() {
    std::string s = "aab";
    Solution slt;
    auto ans = slt.partition(s);
    std::cin.get();
}