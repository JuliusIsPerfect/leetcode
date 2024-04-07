#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;

            // https://leetcode.cn/problems/linked-list-cycle-ii/solutions/12616/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-
            if (slow == fast) {  // slow 和 fast 相遇时，fast 从 head 开始走了 2nb 步，slow 走了 nb 步
                fast = head;
                while (fast != slow) {  // 此时一个指针从 head 开始走 a 步，slow 同时走 a 步，刚好在环入口相遇
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};