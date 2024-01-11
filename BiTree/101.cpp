#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> que;
        TreeNode* cur = root;
        int len = 0;
        que.push(cur);
        while (!que.empty()){
            len = que.size();
            std::vector<int> vec;
            for (int i = 0; i < len; i++){
                cur = que.front();
                que.pop();
                if (cur) que.push(cur->left);
                // else que.push(NULL);
                if (cur) que.push(cur->right);
                // else que.push(NULL);
                if (cur) vec.push_back(cur->val);
                else vec.push_back(2333);
                
            }
            for(int i = 0; i <= len/2; i++){
                if (vec[i] == vec[len - i - 1]) continue;
                else return false;
            }
        }
        return true;
    }
};