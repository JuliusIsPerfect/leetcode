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
    ListNode* insertionSortList(ListNode* head) {
        auto old = head;
        auto dummy = new ListNode;

        while (old) {
            auto nxt = old->next;
            auto cur = dummy;
            while (cur->next && cur->next->val < old->val) {
                cur = cur->next;
            }
            old->next = cur->next;
            cur->next = old;
            old = nxt;
        }
        return dummy->next;
    }
};