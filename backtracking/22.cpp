#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::vector<std::string> res;

    void dfs(std::string path, int l, int r) {
        if (l == 0 && r == 0) {
            res.emplace_back(path);
            return;
        }
        if (l < 0 || l > r) {
            return;
        }
        
        // if ()

        dfs(path + "(", l - 1, r);
        dfs(path + ")", l, r - 1);
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::string path = "";
        dfs(path, n, n);
        return res;
    }
};