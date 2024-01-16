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
    int depth(TreeNode* cur){
        if (cur == nullptr) return 0;
        if (!cur->left && !cur->right) return 1;
        int l = depth(cur->left);
        int r = depth(cur->right);
        if (l >= r) return l + 1;
        else return r + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int l = depth(root->left);
        int r = depth(root->right);

        if (isBalanced(root->left) && isBalanced(root->right)){
            if (l - r >= -1 && l - r <= 1){
            return true;
            }
        }
        return false;
    }
};