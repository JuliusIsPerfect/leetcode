#include <algorithm>
#include <iostream>
#include <vector>

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
    int res = 1;

    int maxdeep(TreeNode* cur) {
        if (!cur) return 0;
        int lmax = maxdeep(cur->left), rmax = maxdeep(cur->right);
        res = std::max(lmax + rmax, res);
        return std::max(lmax, rmax) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) return 0;
        maxdeep(root);
        return res;
    }
};