#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int> > result;
    std::vector<int> pth;
    void backtracking(std::vector<int>& candidates, int target, int sum, int start){
        if (sum > target) return;
        if (sum == target) {
            std::vector<int> tmp = pth;
            // std::sort(tmp.begin(), tmp.end());
            result.push_back(tmp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            pth.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i);
            pth.pop_back();
        }
        return;
    }

    std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main() {
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution slt;
    slt.combinationSum(candidates, target);
    std::cin.get();
}