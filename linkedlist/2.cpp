#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        auto cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    void add(ListNode* list1, ListNode* list2, ListNode* cur, int n) {
        if (!list1 && !list2 && n == 0) {
            return;
        }
        else if (!list1 && !list2 && n != 0) {
            cur->val = n;
            cur->next = new ListNode();
        }
        else if (!list1) {
            cur->next = new ListNode();
            cur->val = (list2->val + n) % 10;
            add(list1, list2->next, cur->next, (list2->val + n) / 10);
        }
        else if (!list2) {
            cur->next = new ListNode();
            cur->val = (list1->val + n) % 10;
            add(list1->next, list2, cur->next, (list1->val + n) / 10);
        }
        else {
            cur->next = new ListNode();
            cur->val = (list1->val + list2->val + n) % 10;
            add(list1->next, list2->next, cur->next, (list1->val + list2->val + n) / 10);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // auto head1 = reverse(l1);
        // auto head2 = reverse(l2);
        ListNode* res = new ListNode;
        add(l1, l2, res, 0);
        return reverse(reverse(res)->next);
    }
};