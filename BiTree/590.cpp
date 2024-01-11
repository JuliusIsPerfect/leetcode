#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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

// N叉树的后序遍历
class Solution {
public:
    std::vector<int> ans;
    std::stack<Node*> st;

    std::vector<int> postorder(Node* root) {
        if (root == nullptr) return ans;
        Node* cur = root;
        st.push(cur);
        while (!st.empty()){
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            for (auto it = cur->children.begin(); it != cur->children.end(); it++){
                st.push(*it);
            }

        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
        
    }
};