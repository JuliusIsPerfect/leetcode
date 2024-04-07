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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto cur = head;
        auto tail = head;

        while (cur) {
            while (tail && tail->val == cur->val) {
                tail = tail->next;
            }
            cur->next = tail;
            cur = cur->next;
        }

        return dummy->next;
    }
};