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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        std::queue<TreeNode*> que;
        TreeNode* cur = root;
        TreeNode* tmp = root;
        que.push(cur);
        int len = 0;
        while (!que.empty()){
            cur = que.front();
            que.pop();
            if (cur == nullptr) continue;
            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            que.push(cur->left);
            que.push(cur->right);

        }
        return root;
    }
};