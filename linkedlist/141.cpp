#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        int len = 0;
        ListNode* p = head;
        while (p && len <= 1e5){
            p = p->next;
            len++;
        }
        if (p == nullptr) return true;
        if (len > 1e5) return false;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* tail = new ListNode(2);
    tail->next = head;
    Solution solution;
    
    std::cin.get();
}