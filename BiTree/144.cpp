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
    void traversal(TreeNode* cur, std::vector<int> &preorder){
        if (cur == NULL) return;
        preorder.push_back(cur->val);
        traversal(cur->left, preorder);
        traversal(cur->right, preorder);
        return;
    }
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> preorder;
        traversal(root, preorder);
        return preorder;
    }
};

TreeNode* buildTree(std::vector<int> nums, int cnt){
    
    if (nums[cnt]){
        TreeNode* cur = new TreeNode(nums[cnt]);
        cur->left = buildTree(nums, 2*cnt + 1);
        cur->right = buildTree(nums, 2*cnt + 2);
        return cur;
    }
    
    return NULL;
}

int main(){
    std::vector<int> nums{1,NULL,2,3};
    TreeNode* root = buildTree(nums, 0);

    std::cin.get();
}