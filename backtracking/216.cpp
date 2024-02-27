#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > result;
    std::vector<int> path;

    void backtracking(int n, int k, int start, int sum) {
        if (path.size() == k && sum == n) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++){
            path.push_back(i);
            backtracking(n, k, i + 1, sum + i);
            path.pop_back();
        }
    }

    std::vector<std::vector<int> > combinationSum3(int k, int n) {
        if (n > 45) return result;
        backtracking(n, k, 1, 0);
        return result;
    }
};

int main(){
    int k = 3;
    int n = 7;
    Solution slt;
    slt.combinationSum3(k, n);
    
    std::cin.get();
}