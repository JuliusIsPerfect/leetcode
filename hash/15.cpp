#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans{};
        struct VectorHash {
            size_t operator()(const std::vector<int>& v) const {
                std::hash<int> hasher;
                size_t seed = 0;
                for (int i : v) {
                    seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
                }
                return seed;
            }
        };
        
        std::unordered_set<std::vector<int>, VectorHash> ans_set;
        std::unordered_set<int> set;
        
        for(int i = 0; i <= nums.size() - 3; i++){
            set.insert(nums[i]);
            for(int j = i + 1; j <= nums.size() - 1; j++){
                if (set.find(nums[j]) == set.end()) set.insert(nums[j]);
                if (set.find(-nums[i] - nums[j]) != set.end()){
                    std::vector<int> tmp{nums[i], -nums[i] - nums[j], nums[j]};
                    // ans.push_back({nums[i], -nums[i] - nums[j], nums[j]});
                    std::sort(tmp.begin(), tmp.end());
                    ans_set.insert(tmp);
                }
                    
            }

        }
        /*
        for (int i = 0; i <= nums.size() - 3; i++){
            for(int j = i + 1; j <= nums.size() - 1; j++){

            }

        }
        */


        for (auto list: ans_set) ans.push_back(list);
        return ans;

    }
};

int main(){
    // std::vector<int> nums{-1,0,1,2,-1,-4};
    std::vector<int> nums{1,2,-2,-1};
    Solution solution;
    auto ans = solution.threeSum(nums);


    std::cin.get();
}