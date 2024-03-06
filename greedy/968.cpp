#include <iostream>
#include <vector>

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
    int cnt;

    void dfs(TreeNode* cur) {
        if (cur == nullptr) return;
        
        dfs(cur->left);
        dfs(cur->right);
        // if(cur->val == 4) return;

        if (!cur->left && !cur->right) {
            cur->val = 1; // 叶
            return;
        }

        if (cur->left && cur->right) {
            if (cur->left->val == 1 || cur->right->val == 1) {
                cur->val = 2;  // 摄像头
                cnt++;
                return;
            }
            if (cur->left->val == 2 || cur->right->val == 2) {
                cur->val = 3;  // 有孩子是摄像头节点
                return;
            }
            if (cur->val == 4) {
                cnt++;
                return;
            }
            cur->val = 1;  // 这个节点应该被上面的监视
            return;
        }

        if (cur->left) {
            if (cur->left->val == 1) {
                cur->val = 2;
                cnt++;
                return;
            }
            if (cur->left->val == 2) {
                cur->val = 3;
                return;
            }
            if (cur->val == 4) {
                cnt++;
                return;
            }
            cur->val = 1;
            return;
        }

        if (cur->right->val == 1) {
            cur->val = 2;
            cnt++;
            return;
        }
        if (cur->right->val == 2) {
            cur->val = 3;
            return;
        }
        if (cur->val == 4) {
            cnt++;
            return;
        }
        cur->val = 1;
        // cnt++;
        return;
    }

    int minCameraCover(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        root->val = 4;
        dfs(root);
        return cnt;    
    }
};