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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ans;
        std::queue<TreeNode*> que;
        TreeNode* cur = root;
        if (root == nullptr) return ans;
        que.push(cur);
        while (!que.empty()){
            cur = que.back();
            int len = que.size();
            ans.push_back(cur->val);
            for (int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            
        }
        return ans;
    }
};