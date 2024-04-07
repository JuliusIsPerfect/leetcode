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
    ListNode* partition(ListNode* head, int x) {
        auto dummy1 = new ListNode;
        auto tail1 = dummy1;
        auto dummy2 = new ListNode;
        auto tail2 = dummy2;

        auto cur = head;
        while (cur) {
            if (cur->val < x) {
                tail1->next = new ListNode(cur->val);
                tail1 = tail1->next;
            }
            else {
                tail2->next = new ListNode(cur->val);
                tail2 = tail2->next;
            }
            cur = cur->next;
        }

        tail1->next = dummy2->next;
        return dummy1->next;
    }
};