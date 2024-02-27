#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int> > result;
    std::vector<int> path;

    void backtracking(int n, int k, int start) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        // for (int i = start; i <= n; i++) {
        // 剪枝
        // path.size()就是当前搜索到的层数
        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

    std::vector<std::vector<int> > combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};