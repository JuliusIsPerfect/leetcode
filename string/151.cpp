#include<iostream>
#include<string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string reversed = "";
        auto iter = s.end() - 1, iter2 = s.end();
        for (; iter != s.begin() - 1; iter--){
            // std::cout << *iter << std::endl;
            if (*iter != ' '){
                iter2 = iter;

                while (iter != s.begin() && *iter != ' ') {
                // while (*iter != ' ') {
                    iter--;
                }
                reversed += std::string (iter, iter2 + 1);
                reversed += " ";
            }
            // iter = iter2;
        }
        reversed.pop_back();
        auto it = reversed.begin();
        while(*it == ' '){
            it++;
            reversed.erase(it-1);
        }
        for (auto it = reversed.begin(); it != reversed.end(); it++)
            if (*it == ' ' && *(it+1) == ' ') reversed.erase(it+1);
        return reversed;
    }
};

int main(){
    std::string s{"the sky is blue"};
    Solution sol;
    auto ans = sol.reverseWords(s);

    std::cin.get();
}