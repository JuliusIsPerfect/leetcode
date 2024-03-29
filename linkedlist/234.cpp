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
    bool judge(std::vector<int>& val) {
        int mid = val.size() / 2;
        for (int i = 0; i < mid; ++i) {
            if (val[i] != val[val.size() - i -1]) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if (!head->next) {
            return false;
        }

        std::vector<int> val;
        auto cur = head;
        while (cur) {
            val.emplace_back(cur->val);
            cur = cur->next;
        }

        return judge(val);
    }
};