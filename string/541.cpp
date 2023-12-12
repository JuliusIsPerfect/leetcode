#include<iostream>
#include<string>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {

        char tmp;
        if (s.size() < k) {
            for (int i = 0; i < s.size()/2; i++){
                tmp = s[s.size() - i - 1];
                s[s.size() - i - 1] = s[i];
                s[i] = tmp;
            }
            return s;
        }
        std::string ans;
        int i;
        for (i = 0; i < s.size(); i += 2*k){
            if (s.size() - i <= k) {
                for (int j = i; j <= i + (s.size() - i)/2; j++){
                    tmp = s[j];
                    s[j] = s[s.size()-(j-i)];
                    s[s.size()-(j-i)] = tmp;
                }

            }
            else{
                for (int j = i; (j < i + k/2) && (j < s.size()); j++){
                    if (i + k - (j - i) - 1 >= s.size()) break;
                    tmp = s[j];
                    s[j] = s[i + k - (j - i) - 1];
                    s[i + k - (j - i) - 1] = tmp;
                }

            }

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