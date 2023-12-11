#include<iostream>
#include<vector>
#include<unordered_map>
/*
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> idx;
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target) return std::vector<int> {i, j};
            }
        }
        
        return std::vector<int> {};
    }
};
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {

            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }

            map.insert(std::pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};

int main(){
    // std::vector<int> nums = {2,7,11,15};
    std::vector<int> nums = {3,2,4};
    int target = 6;
    Solution solution;
    std::vector<int> ans = solution.twoSum(nums, target);

    std::cin.get();
}