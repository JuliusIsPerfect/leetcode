#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    void getNext(std::vector<int> &next, const std::string& s) {
        /*
        如何更好地理解和掌握 KMP 算法? - 海纳的回答 - 知乎
        https://www.zhihu.com/question/21923021/answer/281346746
        求next数组的过程完全可以看成字符串匹配的过程，
        即以模式字符串为主字符串，以模式字符串的前缀为目标字符串，
        一旦字符串匹配成功，那么当前的next值就是匹配成功的字符串的长度。
        */
        int j = 0;
        next[0] = 0;
        // aabaabaaf
        // aabaaf
        // ababc
        // abcaabc
        // i是当前试图匹配的后缀的末尾，j是相应的前缀的末尾
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1]; // j向前跳，寻找可能的更短的相同前缀继续匹配
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        std::vector<int> next(needle.size());
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

/*
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int first = 0;
        first = haystack.find(needle);
        if (first != std::string::npos)
            return first;
        else
            return -1;
    }
};
*/

int main(){
    const char* haystack = "sadbutsad";
    const char* needle = "sad";

    Solution slt;
    int ans = slt.strStr(haystack, needle);
    std::cout<< ans << std::endl;

    std::cin.get();
}
