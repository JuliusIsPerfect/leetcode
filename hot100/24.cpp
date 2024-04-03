#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto dummy = new ListNode;
        dummy->next = head;
        auto cur = dummy;

        while (cur->next && cur->next->next) {
            auto cur1 = cur->next;
            auto cur2 = cur1->next;

            cur->next = cur2;
            cur1->next = cur2->next;
            cur2->next = cur1;
            cur = cur1;
        }

        return dummy->next;
    }
};