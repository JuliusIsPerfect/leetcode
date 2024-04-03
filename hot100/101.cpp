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
    bool cmp(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (left && !right) return false;
        if (right && !left) return false;
        if (left->val != right->val) return false;

        bool leftcmp = cmp(left->left, right->right);
        bool rightcmp = cmp(left->right, right->left);
        return leftcmp && rightcmp;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return cmp(root->left, root->right);
    }
};