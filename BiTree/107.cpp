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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> ans;

        if (root == nullptr) return ans;

        int len = 0;
        TreeNode* cur = root;
        que.push(cur);

        while (!que.empty()){
            std::vector<int> tmp;
            len = que.size();
            for (int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back(tmp);
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

