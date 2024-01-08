#include <iostream>
#include <string>
#include <vector>

class Solution {
public:

    bool repeatedSubstringPattern(std::string s) {
        // abcabcabc
        std::string t = s + s;
        t.erase(t.begin()); t.erase(t.end() - 1); 
        if (t.find(s) != std::string::npos) return true; 
        return false;
    }
};

int main(){
    std::string s("abab");
    Solution slt;
    bool ans = slt.repeatedSubstringPattern(s);
    std::cout << ans << std::endl;

    std::cin.get();
}