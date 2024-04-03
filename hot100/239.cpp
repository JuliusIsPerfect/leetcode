#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    class Mqueqe {
        std::deque<int> que;

    public:
        void push(int x) {
            while (!que.empty() && que.back() < x) {
                que.pop_back();
            }
            que.push_back(x);
        }

        void pop(int x) {
            if (!que.empty() && que.front() == x)
                que.pop_front();
        }

        int front() {
            return que.front();
        }
    };

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res{};
        Mqueqe que;

        for (int i = 0; i < nums.size() && i < k; ++i) {
            que.push(nums[i]);
        }
        res.push_back(que.front());

        for (int i = k; i < nums.size(); ++i) {
            que.push(nums[i]);
            que.pop(nums[i - k]);
            res.push_back(que.front());
        }

        return res;
    }
};