#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 找到空结点或者pq之一就向上
        if (root == nullptr || root == p || root == q) return root;

        // 前序遍历
        // 得到的left,right要么是p,q,要么是下面return上来的pq最近公共祖先
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right) return nullptr; // pq不在root的左右子树
        if (!left) return right; // 左子树没找到，右子树找到，right是p或q或return的最近公共祖先
        if (!right) return left; // left是下面找到的p或q或return上来的最近公共祖先

        // pq位于root的左右子树
        // 第一个到这里的root就是最近公共祖先，一路return上去
        // 接下来不会再有root到这里，因为不会有pq位于当前结点左右子树的情况，只会在一边或者没有
        return root;
    }
};