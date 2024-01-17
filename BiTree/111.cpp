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
    int minDepth(TreeNode* root) {
        int min = 0;
        if (root == nullptr) return 0;

        std::queue<TreeNode*> que;
        TreeNode* cur = root;
        que.push(cur);
        int len = 0;
        
        while (!que.empty()){
            len = que.size();
            if (len) min++;
            for (int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                if (!cur->left && !cur->right) return min;
                else{
                    if (cur->left) que.push(cur->left);
                    if (cur->right) que.push(cur->right);
                }
            }
            
        }

        return min;
    }
};