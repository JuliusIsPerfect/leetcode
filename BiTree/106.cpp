#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    std::unordered_map<int, int> inmap;
    int len;

    TreeNode* travel(int instart, int inend, 
        std::vector<int>& inorder, std::vector<int>& postorder){
        if (instart > inend) return nullptr;

        int root_val = postorder[len];
        TreeNode* root = new TreeNode(root_val);
        int index = inmap[root_val];
        len--;
        
        root->right = travel(index + 1, inend, inorder, postorder);
        root->left = travel(instart, index - 1, inorder, postorder);
        
        return root;
    }

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        len = inorder.size() - 1;
        int idx = 0;

        for (auto& i:inorder){
            inmap[i] = idx++;
        }

        TreeNode* root = travel(0, inorder.size() - 1, inorder, postorder);
        return root;
    }
};