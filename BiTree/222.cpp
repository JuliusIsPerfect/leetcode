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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        TreeNode* left = root->left;
        TreeNode* right =root->right;
        int l = 0, r = 0;

        while (left){
            left = left->left;
            l++;
        }
        while (right){
            right = right->right;
            r++;
        }
        if (l == r) return (2<<l) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};