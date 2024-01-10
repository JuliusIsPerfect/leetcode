#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> map;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); i++){
            // if (map.find(nums[i]) == map.end()) map.insert({nums[i], 1});
            // else map[nums[i]]++;
            map[nums[i]]++;
        }
        /*
        auto it = map.begin();
        for (int i = 0; i < k; i++){
            result.push_back(it->first);
            it++;
        }        
        */
        // map迭代器创建vector
        // std::map中的每一个元素都是一个std::pair
        // 键值对的键是pair::first，值是pair::second
        std::vector<std::pair<int, int>> vec(map.begin(), map.end());

        // 如果比较函数返回true，那么第一个参数应该在第二个参数之前
        std::sort(vec.begin(), vec.end(), 
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k && i < vec.size(); i++){
            result.push_back(vec[i].first);
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