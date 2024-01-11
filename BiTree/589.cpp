#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// N叉树的前序遍历
class Solution {
public:
    std::vector<int> ans;
    std::vector<int> preorder(Node* root) {
        if (root == nullptr) return ans;
        ans.push_back(root->val);
        for (auto it = root->children.begin(); it != root->children.end(); it++)
            preorder(*it);
        return ans;
    }
};

