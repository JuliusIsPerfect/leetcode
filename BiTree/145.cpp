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
    void traversal(TreeNode* cur, std::vector<int> &postorder){
        if (cur == NULL) return;
        traversal(cur->left, postorder); 
        traversal(cur->right, postorder);
        postorder.push_back(cur->val);
        return;
    }
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> postorder;
        traversal(root, postorder);
        return postorder;
    }
};