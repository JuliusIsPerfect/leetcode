#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        char tmp;
        int len = s.size();
        for (int i = 0; i < len/2; i++){
            tmp = s[len - i - 1];
            s[len - i - 1] = s[i];
            s[i] = tmp;
        }
    }
};
int main(){
    std::vector<char> s{'A',' ','m','a','n',',',' ','a',' ','p','l','a','n',',',' ','a',' ','c','a','n','a','l',':',' ','P','a','n','a','m','a'};
    Solution sol;
    sol.reverseString(s);

    std::cin.get();
}