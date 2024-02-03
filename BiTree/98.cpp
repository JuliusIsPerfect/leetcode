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

// 中序遍历下，输出的二叉搜索树结点的数值是有序序列
// 验证二叉搜索树，相当于判断中序结点序列是不是递增
class Solution {
public:
    TreeNode* pre = nullptr;
    long long max = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool left = isValidBST(root->left);
        if (max < root->val) max = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};