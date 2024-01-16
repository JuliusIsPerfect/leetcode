#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
    std::vector<int> path;
    std::vector<std::string> result;
    void travel(TreeNode* cur, std::vector<int> &path, std::vector<std::string> &result){
        path.push_back(cur->val);
        if (!cur->left && !cur->right){
            int len = path.size();
            std::string spath;
            for (int i = 0; i < len - 1; i++){
                spath += std::to_string(path[i]);
                spath += "->";
            }
            spath += std::to_string(path[len - 1]);
            result.push_back(spath);
            return;
        }

        if (cur->left){
            travel(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right){
            travel(cur->right, path, result);
            path.pop_back();
        }
        return;
    }
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return result;
        travel(root, path, result);
        return result;
    }
};