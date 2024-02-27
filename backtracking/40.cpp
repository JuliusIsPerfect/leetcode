#include "iostream"
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> pth;
    std::vector<std::vector<int>> result;

    void backtracking(std::vector<int>& candidates, int& target, int start, int sum){
        if (sum > target) return;
        if (sum == target) {
            result.push_back(pth);
            return;
        }

        for (int i = start; i < candidates.size(); i++){
            /*
            i > start:
            从上往下递归，同一条搜索路径pth，允许出现重复元素。也就是每到一层，选它的第一个元素是不受上面选取情况的限制的。
                  1,1,1,2
                 /
               1,1,1,2       i == start 保证同一路径，向下递归时可以选取到相等元素（每次选到的1都是当前层的start元素）
                / 
            1,1,1,2
            candidates[i] == candidates[i - 1]:
            搜索树的同一层（也就是同一个for中），不允许选取与上一个相等的元素。
            因为前面第一个与它相等的元素已经把选取这个元素的搜索路径都走完了。
            */
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            pth.push_back(candidates[i]);
            backtracking(candidates, target, i + 1, sum + candidates[i]);
            pth.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main() {
    std::vector<int> candidates = {2};
    int target = 1;
    Solution slt;
    slt.combinationSum2(candidates, target);
    std::cin.get();
}