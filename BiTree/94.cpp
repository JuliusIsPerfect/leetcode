#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
class Solution {
public:
    void traversal(TreeNode* cur, std::vector<int> &inorder){
        if (cur == NULL) return;
        traversal(cur->left, inorder);
        inorder.push_back(cur->val);
        traversal(cur->right, inorder);
        return;
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> inorder;
        traversal(root, inorder);
        return inorder;
    }
};
*/
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> inorder;
        std::stack<TreeNode*> st;
        if (root == NULL) return inorder;
        // st.push(root);
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()){
            if (cur == NULL){
                cur = st.top();
                st.pop();
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                st.push(cur);
                cur = cur->left;
            }
        }
        return inorder;
    }
};