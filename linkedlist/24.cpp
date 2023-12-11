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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;
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
    std::vector<int> arr = {1,2,3,4};
    ListNode* head = create(arr);
    Solution solution;
    ListNode* ans = solution.swapPairs(head);
    std::cin.get();
}