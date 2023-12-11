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
        if (headA == nullptr || headB == nullptr) return nullptr;
        int lenA = 0, lenB = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA){
            pA = pA->next;
            lenA++;
        }
        while (pB){
            pB = pB->next;
            lenB++;
        }

        pA = headA; pB = headB;
        if (lenA == lenB){
            while(lenA--){
                if (pA == pB) return pA;
                pA = pA->next;
                pB = pB->next;
            }
            return nullptr;
        }

        if (lenA > lenB){
            int diff = lenA - lenB;
            while (diff--) pA = pA->next;
            while (lenB--){
                if (pA == pB) return pA;
                pA = pA->next;
                pB = pB->next;
            }
        
        }

        if (lenB > lenA){
            int diff = lenB - lenA;
            while (diff--) pB = pB->next;
            while (lenA--){
                if (pA == pB) return pA;
                pA = pA->next;
                pB = pB->next;
            }
        
        }

        return nullptr;
    }
};

int main(){
    ListNode* headA = new ListNode(1);
    ListNode* headB = new ListNode(2);
    Solution solution;
    ListNode* ans = solution.getIntersectionNode(headA, headB);

    std::cin.get();
}