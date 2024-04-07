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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        else if (!l2) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeList(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeList(l1, l2->next);
            return l2;
        }
    }

    ListNode* cut(ListNode* head, int n) {
        auto cur = head;
        while (--n && cur) {
            cur = cur->next;
        }

        if (!cur) {
            return nullptr;
        }

        auto nxt = cur->next;
        cur->next = nullptr;
        return nxt;
    }

    ListNode* sortList(ListNode* head) {
        int len = 0;
        auto cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        if (len == 0 || len == 1) {
            return head;
        }

        ListNode* dummyHead = new ListNode(0, head);
        for (int i = 1; i < len; i <<= 1) {
            auto cur = dummyHead->next;
            auto tail = dummyHead;

            while (cur) {
                auto left = cur;
                auto right = cut(left, i);
                cur = cut(right, i);

                tail->next = mergeList(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }

        return dummyHead->next;
    }
};