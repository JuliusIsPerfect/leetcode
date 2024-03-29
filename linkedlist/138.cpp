#include <corecrt.h>
#include<iostream>
#include <unordered_map>
#include<vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto oldlist = head;
        std::unordered_map<Node*, Node*> map;

        while (oldlist) {
            map[oldlist] = new Node(oldlist->val);
            oldlist = oldlist->next;
        }

        oldlist = head;
        while (oldlist) {
            map[oldlist]->next = map[oldlist->next];
            map[oldlist]->random = map[oldlist->random];
            oldlist = oldlist->next;
        }

        return map[head];
    }
};