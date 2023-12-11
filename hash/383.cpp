#include<iostream>
#include<string>
#include<unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // bool flag = 0;
        std::unordered_map<char, int> map1, map2;
        for (auto s: ransomNote) map1[s]++;
        for (auto s: magazine) map2[s]++;

        for (auto it: map1)
            if (map2[it.first] < map1[it.first]) return false;
        return true;
        // return flag;
    }
};

int main(){
    const char* ransomNote = "aa";
    const char* magazine = "ab";
    Solution solution;
    bool ans = solution.canConstruct(ransomNote, magazine);

    std::cin.get();
}