#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
std::vector<std::string> str2vec(std::string& s){
    std::string str;
    // std::vector<int> vec;
    std::vector<std::string> nodevec;
    if (s == "") return nodevec;

    for (auto& c:s){
        if (c == ',') {
            nodevec.push_back(str);
            str.clear();
        }
        else {
            str.push_back(c);
        }
    }
    if (str != "") nodevec.push_back(str);
    
    return nodevec;
}

TreeNode* createTree(std::vector<std::string>& svec){
    if (svec.empty()) return nullptr;

    std::queue<TreeNode*> que;
    int idx = 1;
    TreeNode* root = new TreeNode(stoi(svec[idx - 1]));
    TreeNode* cur = root;
    que.push(cur);

    while (!que.empty()) {
        cur = que.front();
        que.pop();
        if (idx >= svec.size()) break;
        if (svec[idx] != "null"){
            cur->left = new TreeNode(stoi(svec[idx]));
            que.push(cur->left);
        }
        idx++;
        if (svec[idx] != "null"){
            cur->right = new TreeNode(stoi(svec[idx]));
            que.push(cur->right);
        }
        idx++;
    }

    return root;
}
*/

class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string stree;
        if (root == nullptr) return stree;
        
        std::vector<int> vtree;
        std::queue<TreeNode*> qtree;
        TreeNode* cur = root;
        qtree.push(cur);

        while (!qtree.empty()) {
            cur = qtree.front();

            if (cur != nullptr) vtree.push_back(cur->val);
            else vtree.push_back(2333);
            qtree.pop();
            
            if (cur) {
                qtree.push(cur->left);
                qtree.push(cur->right);
            }
        }
        
        for (auto& i:vtree) {
            if (i == 2333) stree += "null,";
            else {
                stree += std::to_string(i);
                stree += ',';
            }
        }
        stree.pop_back();

        return stree;
    }

    std::vector<std::string> str2vec(std::string& s){
        std::string str;
        // std::vector<int> vec;
        std::vector<std::string> nodevec;
        if (s == "") return nodevec;

        for (auto& c:s){
            if (c == ',') {
                nodevec.push_back(str);
                str.clear();
            }
            else {
                str.push_back(c);
            }
        }
        if (str != "") nodevec.push_back(str);
        
        return nodevec;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        auto svec = str2vec(data);

        if (svec.empty()) return nullptr;

        std::queue<TreeNode*> que;
        int idx = 1;
        TreeNode* root = new TreeNode(stoi(svec[idx - 1]));
        TreeNode* cur = root;
        que.push(cur);

        while (!que.empty()) {
            cur = que.front();
            que.pop();
            if (idx >= svec.size()) break;
            if (svec[idx] != "null"){
                cur->left = new TreeNode(stoi(svec[idx]));
                que.push(cur->left);
            }
            idx++;
            if (svec[idx] != "null"){
                cur->right = new TreeNode(stoi(svec[idx]));
                que.push(cur->right);
            }
            idx++;
        }

        return root;
    }
};

int main(){
    std::string s = "1,null,3,4,5";
    // std::string s = "1,2,3,null,null,4,5";

    // std::vector<std::string> vtree = str2vec(s);
    // TreeNode* root = createTree(vtree);

    std::cin.get();
}