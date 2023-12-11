#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while (p1){
            lenA++;
            p1 = p1->next;
        }
        while (p2){
            lenB++;
            p2 = p2->next;
        }

        ListNode* start = nullptr;
        if (lenA == 0 or lenB == 0) return start;
        p1 = headA; p2 = headB;
        if (lenA == lenB){
            while (lenA--){
                if (p1 == p2) return p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            // if (lenA < 0)
            return nullptr;
            
        }
        if (lenA > lenB){
            int diff = lenA - lenB;
            while (lenA--) p1 = p1->next;
            while (lenA--){
                if (p1 == p2) return p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            return nullptr;
        }
        if (lenA < lenB){
            int diff = lenB - lenA;
            while (lenB--) p1 = p1->next;
            while (lenB--){
                if (p1 == p2) return p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            return nullptr;
        }
        return nullptr;
    }
};

int main(){


    std::cin.get();
}