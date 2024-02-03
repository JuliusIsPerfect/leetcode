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
    TreeNode* pre = nullptr;
    int min_diff = INT32_MAX;

    void traversal(TreeNode* root){
        if (!root) return;
        
        traversal(root->left);
        if (pre) {
            if (root->val - pre->val < min_diff) min_diff = root->val - pre->val;
        }
        pre = root;

        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);

        return min_diff;
    }
};