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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* tail = head;
        int len = 0;
        while(tail->next != nullptr){
            // len++;
            ListNode* tmp = tail->next;
            
            tail = tail->next;
        }
        
        
    }
};

/*
ListNode* createlist(std::vector<int>& arr){
    ListNode* tail = new ListNode;
    if (arr.empty()) return tail;
    tail = ListNode(arr[0]);
    for (int i = 1; i < arr.size(); i++){


    }
}
*/


int main(){
    std::vector<int> arr = {1,2,3,4,5};
    Solution solution;
    ListNode* head;
    solution.reverseList(head);

    std::cin.get();
}