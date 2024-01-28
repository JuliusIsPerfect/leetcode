#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> vec;
    bool flag = false;
    int tar;
    void dfs(TreeNode* cur, int now){
        int sum = cur->val + now;
        if (!cur->left && !cur->right) {
            if (sum == tar) flag = true;
            return;
        }
        if (flag == false && cur->left) dfs(cur->left, sum);
        if (flag == false && cur->right) dfs(cur->right, sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        tar = targetSum;
        dfs(root, 0);

        return flag;
    }
};