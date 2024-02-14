#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    // std::unordered_map<int, char> map;
    std::vector<std::string> result;
    std::string pth;

    void backtracking(int idx, std::string& d) {
        if (idx > d.length()) return;
        if (idx == d.length()) {
            result.push_back(pth);
            return;
        }
        int num = d[idx] - '0';
        if (num >= 2 && num <= 6) {
            for (int i = 0; i <= 2; i++) {
                pth += 'a' + 3 * (num - 2) + i;
                backtracking(idx + 1, d);
                pth.pop_back();
            }
        }
        else if (num == 7) {
            for (int i = 0; i <= 3; i++) {
                pth += 'p' + i;
                backtracking(idx + 1, d);
                pth.pop_back();
            }
        }
        else if (num == 8) {
            for (int i = 0; i <= 2; i++) {
                pth += 't' + i;
                backtracking(idx + 1, d);
                pth.pop_back();
            }
        }
        else if (num == 9) {
            for (int i = 0; i <= 3; i++) {
                pth += 'w' + i;
                backtracking(idx + 1, d);
                pth.pop_back();
            }

        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        if (!digits.length()) return result;
        backtracking(0, digits);
        return result;
    }
};

int main(){
    std::string sss = "23";
    Solution slt;
    slt.letterCombinations(sss);
    std::cin.get();
}