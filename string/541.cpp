#include<iostream>
#include<string>
#include<algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        char tmp;
        for (int i = 0; i < s.size(); i += 2*k){
            if (s.size() - i < k){
                reverse(s.begin() + i, s.end());
            }
            else reverse(s.begin() + i, s.begin() + i + k);
        }

        return s;
    }
};

int main(){
    std::string s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    int k = 39;
    // std::cin >> k;
    Solution sol;
    sol.reverseStr(s, k);

    std::cin.get();
}