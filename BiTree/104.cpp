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
    // int depth;
    /*
    int dig(TreeNode* cur, int dep){
        int ldepth, rdepth;
        if (cur->left) ldepth = dig(cur->left, dep + 1);
        if (cur->right) rdepth = dig(cur->right, dep + 1);
        if (ldepth >= rdepth) return ldepth;
        return rdepth;
    }    
    */

    int maxDepth(TreeNode* root) {
        int depth = 0, ld = 0, rd = 0;
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left) ld = maxDepth(root->left) + 1;
        if (root->right) rd = maxDepth(root->right) + 1;

        if (ld >= rd) return ld;
        return rd;
        
    }
};