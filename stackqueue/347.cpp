#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>

class Solution {
public:
    class myQueue{
    public:
        std::deque<int> q;

        void pop(int value){
            if (!q.empty() && q.front() == value) q.pop_front();
        }

        void push(int value){
            while (!q.empty() && q.back() < value){ // 不能取<=，因为可以存在不止一个最大值
                q.pop_back();
            }
            q.push_back(value);

        }

        int front(){
            return q.front();
        }

    };
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_multiset<int> set;
        std::map<int, int> map;
        myQueue que;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++){
            // if (map.find(nums[i]) == map.end()) map.insert({nums[i], 1});
            // else map[nums[i]]++;
            map[nums[i]]++;
        }
        
        auto it = map.begin();
        for (int i = 0; i < k; i++){
            result.push_back(it->first);
            it++;
        }

        return result;
    }
};

int main(){
    std::vector<int> nums{4,1,-1,2,-1,2,3}; // [2, -1]
    int k = 2;
    Solution slt;
    auto ans = slt.topKFrequent(nums, k);
    std::cin.get();
}