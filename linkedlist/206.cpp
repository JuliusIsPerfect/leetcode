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
        if (head == nullptr || head->next == nullptr) return head;
        int len = 0;
        std::vector<int> array(5000);
        ListNode* p = head;
        while(p){
            array[len] = p->val;
            p = p->next;
            len++;
        }

        ListNode* tail = new ListNode(array[len-1]);
        for (int i = 0; i < len - 1; i++){
            ListNode* q = new ListNode(array[i]);
            q->next = tail->next;
            tail->next = q;
        }
        return tail;
    }
};

ListNode* create(std::vector<int>& arr){
    // if (arr.empty()) return tail;
    ListNode* head = new ListNode(arr[0]);

    for(int i = arr.size()-1; i > 0; i--){
        ListNode* tail = new ListNode(arr[i]);
        tail->next = head->next;
        head->next = tail;

    }
    return head;
}

int main(){
    std::vector<int> arr = {1,2,3,4,5};
    ListNode* head = create(arr);
    Solution solution;
    ListNode* ans = solution.reverseList(head);
    std::cin.get();
}