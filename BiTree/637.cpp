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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ans;
        std::queue<TreeNode*> que;
        TreeNode* cur = root;
        int len = 0;
        long long sum = 0;
        que.push(cur);
        while (!que.empty()){
            len = que.size();
            sum = 0;
            for (int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                sum += (long long)cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back(sum*1.0/len);
        }
        return ans;
    }
};