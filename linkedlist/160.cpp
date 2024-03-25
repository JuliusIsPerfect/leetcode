#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        auto cur = headA;
        while (cur) {
            cur = cur->next;
            ++lenA;
        }
        cur = headB;
        while (cur) {
            cur = cur->next;
            ++lenB;
        }

        while (lenA > lenB) {
            --lenA;
            headA = headA->next;
        }
        while (lenB > lenA) {
            --lenB;
            headB = headB->next;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};