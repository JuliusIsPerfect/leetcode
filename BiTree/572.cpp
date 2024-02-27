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
    bool compare(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;
        else if (!p && q) return false;
        else if (p && !q) return false;
        else if (p->val != q->val) return false;

        bool lcompare = compare(p->left, q->left);
        bool rcompare = compare(p->right, q->right);

        return lcompare && rcompare;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;

        std::queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur = root;
        bool result = false;

        while (!que.empty()){
            cur = que.front();
            que.pop();
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            if (cur->val == subRoot->val){
                result = compare(cur, subRoot);
                if (result) return true;
            }
        }
        return false;
    }
};