#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxdepth = -1, ans = 0;
    void dfs(TreeNode* cur, int curdepth){
        if (curdepth > maxdepth){
            maxdepth = curdepth;
            ans = cur->val;
        }
        if (cur->left) dfs(cur->left, curdepth + 1);
        if (cur->right) dfs(cur->right, curdepth + 1);
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};