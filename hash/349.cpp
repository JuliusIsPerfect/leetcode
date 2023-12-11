#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1, set2;
        for (int i = 0; i < nums1.size(); i++) set1.insert(nums1[i]);

        for (int num: nums2){
            if (set1.find(num) != set1.end()) set2.insert(num);
        }
        
        return std::vector<int>(set2.begin(), set2.end());
    }
};

int main(){
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};
    Solution solution;
    std::vector<int> ans = solution.intersection(nums1, nums2);

    std::cin.get();
}