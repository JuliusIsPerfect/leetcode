#include <iostream>
#include <queue>
#include <stack>

class Solution {
public:
    class myQueue{
    public:
        std::deque<int> q;

        void pop(int value){
            if (!q.empty() && q.front() == value) q.pop_front();
        }

        void push(int value){
            while (!q.empty() && q.back() < value){
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