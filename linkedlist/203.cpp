#include<iostream>
#include<vector>

/**
 * Definition for singly-linked list.\ 
 **/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/**/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        while(head && head->val == val) head = head->next;
        if (!head) return head;
        ListNode* p = head;
        // p->next = head->next;
        while(p->next){
            if (p->next->val == val)
                p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};

int main(){
    std::vector<int> arr = {1,2,6,3,4,5,6};

    int val = 6;
    ListNode* head = new ListNode(arr[0]);
    head->next = nullptr;
    for (int i = arr.size()-1; i > 0; i--){
        ListNode *temp = new ListNode(arr[i]);
        temp->next = head->next;
        head->next = temp;
    }
    Solution solution;
    auto newhead = solution.removeElements(head, val);
    std::cin.get();
}