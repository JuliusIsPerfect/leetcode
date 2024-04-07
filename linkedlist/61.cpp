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
    ListNode *cut(ListNode* head, int len) {
        auto cur = head;
        while (--len && cur) {
            cur = cur->next;
        }
        auto nxt = cur->next;
        cur->next = nullptr;
        return nxt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int l = 0;
        auto cur = head;
        while (cur) {
            ++l;
            cur = cur->next;
        }
        k = k % l;
        
        auto second = cut(head, l - k);

        cur = second;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        return second;
    }
};