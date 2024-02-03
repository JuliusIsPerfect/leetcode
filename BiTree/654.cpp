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
    TreeNode* traversal(std::vector<int>& nums, int start, int end){
        if (start > end) return nullptr;

        int max = -1;
        int maxidx = 0;
        for (int i = start; i <= end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxidx = i;
            }
        }

        TreeNode* root = new TreeNode(max);
        root->left = traversal(nums, start, maxidx - 1);
        root->right = traversal(nums, maxidx + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};