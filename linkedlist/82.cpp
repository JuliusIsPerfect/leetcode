#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        auto dummy = new ListNode();
        // dummy->next = head;
        auto tail = dummy;
        auto prev = head;
        auto cur = head->next;

        if (head->val != head->next->val) {
            tail->next = new ListNode(head->val);
            tail = tail->next;
        }

        while (cur) {
            if (prev->val != cur->val) {
                if (cur->next && cur->next->val != cur->val || !cur->next) {
                    tail->next = new ListNode(cur->val);
                    tail = tail->next;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};