#include <iostream>
#include <queue>
#include <stack>

class Solution {
public:
    class myQueue{
    public:
        std::deque<int> q;

        void pop(int value){
            // 窗口向右滑动一位，弹出最左边元素
            // 要弹出的窗口最左元素要么不在单调队列中，要么就在队列的最左边（出口）
            // 单调队列内的元素的相对前后顺序和它们在原数列的相对顺序是相同的，左边的元素先进入队列
            // 同时要保证单调性
            if (!q.empty() && q.front() == value) q.pop_front();
        }

        void push(int value){
            // 窗口向右滑动一位，push最右元素
            // 如果push进来的新元素比队尾大，那么队尾元素就必须弹出
            // 否则违反单调队列的单调性（这里是单调不增的队列）
            while (!q.empty() && q.back() < value){ // 不能取<=，因为可以存在不止一个最大值
                q.pop_back();
            }
            q.push_back(value);

        }

        int front(){
            return q.front();
        }

    };

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ans;
        myQueue q;
        for (int i = 0; i < k; i++){
            q.push(nums[i]);
        }
        ans.push_back(q.front());
        for(int i = k; i < nums.size(); i++){
            q.pop(nums[i - k]);
            q.push(nums[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
};

int main(){
    std::vector<int> nums{-7,-8,7,5,7,1,6,0};
    int k = 4;
    Solution slt;
    std::vector<int> ans = slt.maxSlidingWindow(nums, k);

    std::cin.get();
}