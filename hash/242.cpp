#include<iostream>
#include<set>
#include<string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int len_s = s.size(), len_t = t.size();
        if (len_s != len_t) return false;
        int arr_s[26] = {0}, arr_t[26] = {0};
        for (int i = 0; i < len_s; i++)
            arr_s[s[i]-'a']++;
        for (int i = 0; i < len_t; i++)
            arr_t[t[i]-'a']++;
        for (int i = 0; i < 26; i++)
            if (arr_s[i] != arr_t[i]) return false;
        return true;
    }
};
int main(){
    const char* s = "anagram";
    const char* t = "nagaram";
    Solution solution;
    bool ans = solution.isAnagram(s, t);

    std::cin.get();
}