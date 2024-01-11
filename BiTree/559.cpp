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

class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0, maxdepth = 0;
        if (!root) return 0;
        
        int len = root->children.size();
        if (!len) return 1;
        for (int i = 0; i < len; i++){
            if (root->children[i]) depth = maxDepth(root->children[i]);
            if (depth > maxdepth) maxdepth = depth;
        }
        maxdepth++;
        return maxdepth;
    }
};