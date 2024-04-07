#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        std::vector<ListNode *> vec;
        auto cur = head;
        while (cur) {
            vec.emplace_back(cur);
            cur = cur->next;
        }

        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            ++i;

            // if (i == j) break;
            
            vec[j]->next = vec[i];
            --j;
        }
        vec[i]->next = nullptr;
    }
};