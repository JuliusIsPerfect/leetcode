#include <iostream>
#include <vector>
#include <queue>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p && q) return false;
        else if (p && !q) return false;
        else if (p->val != q->val) return false;

        bool lcompare = isSameTree(p->left, q->left);
        bool rcompare = isSameTree(p->right, q->right);

        return lcompare && rcompare;
    }
};