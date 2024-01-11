#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> ans;
        TreeNode* cur = root;
        int len;

        if (root == nullptr) return ans;

        que.push(root);
        while(!que.empty()){
            len = que.size();
            std::vector<int> tmp;
            for (int i = 0; i < len; i++){
                cur = que.front();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                tmp.push_back(cur->val);
                que.pop();
            }
            ans.push_back(tmp);

        }
        return ans;
    }
};
*/
class Solution {
public:
    void order(TreeNode* cur, std::vector<std::vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        // 当遍历到一个新的深度，需要在result中添加一个新的vector
        if (result.size() == depth) result.push_back(std::vector<int>());

        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};

int main(){
    

    std::cin.get();
}