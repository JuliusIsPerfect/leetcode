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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        
        ListNode* p = head;
        int len = 0;
        std::vector<int> arr(30);
        while(p){
            arr[len] = p->val;
            p = p->next;
            len++;
        }
        if (len == 1){
            ListNode* a = nullptr;
            return a;
        }
        if (n == len) return head->next;
        p = head;
        for(int i = 1; i <= len - n - 1; i++) p = p->next;
        if (n == 1) p->next = nullptr;
        else p->next = p->next->next;

        return head;
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
    // std::vector<int> arr = {1,2,3,4,5};
    std::vector<int> arr = {1,2};
    ListNode* head = create(arr);
    int n;
    std::cin >> n;
    Solution solution;
    ListNode* ans = solution.removeNthFromEnd(head, n);
    std::cin.get();
}