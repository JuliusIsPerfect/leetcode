#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return slow;
        }
        return nullptr;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* tail = new ListNode(2);
    head->next = tail;
    tail->next = head;
    Solution solution;
    ListNode* ans = solution.detectCycle(head);
    std::cin.get();
}