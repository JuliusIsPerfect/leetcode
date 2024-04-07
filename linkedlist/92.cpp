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
    void reverse(ListNode* head) {
        ListNode* prev = nullptr;
        auto cur = head;
        while (cur) {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        // return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }

        auto tail = pre;
        for (int i = 0; i <= right - left; ++i) {
            tail = tail->next;
        }

        auto post = tail->next;
        auto mid = pre->next;

        pre->next = nullptr;
        tail->next = nullptr;

        reverse(mid);

        pre->next = tail;
        mid->next = post;
        return dummyNode->next;
    }
};