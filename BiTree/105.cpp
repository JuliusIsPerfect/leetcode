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
    int preidx = 0;
    std::unordered_map<int, int> map;

    TreeNode* traversal(int start, int end, 
        std::vector<int>& preorder, std::vector<int>& inorder) {
        if (start > end) return nullptr;

        // 从前/后序遍历中找到当前子树的根
        // 再到map中找到当前根节点在中序遍历中的位置
        // 再根据根在中序的位置，划分出左右两棵子树
        int root_val = preorder[preidx];
        int root_idx = map[root_val];
        TreeNode* root = new TreeNode(root_val);

        preidx++;
        // 注意左右子树创建顺序
        // 前序遍历从前往后先创建左子树，后序从后往前先创建右子树
        root->left = traversal(start, root_idx - 1, preorder, inorder);
        root->right = traversal(root_idx + 1, end, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int idx = 0;
        
        // 用一个map保存某个值在中序遍历中的序号
        // 为接下来在中序遍历中用根节点划分它的左右子树
        for (auto& i : inorder) {
            map[i] = idx++;
        }

        TreeNode* root = traversal(0, preorder.size() - 1, preorder, inorder);
        return root;
    }
};