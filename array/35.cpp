#include <iostream>
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(target < nums[0]) return 0;
        int l = 0, mid = 0, r = nums.size()-1;
            while(l <= r){
                mid = l + (r - l)/2;
                if(target == nums[mid]) return mid;
                else if(target < nums[mid]){
                    r = mid - 1;
                    continue;
                }
                else l = mid + 1;
                
            }
        return mid+1;
    }
};


int main(){
    std::vector<int> nums;
    nums = {1,3,5,6};
    int tar;
    std::cout << "input:";
    std::cin >> tar;
    Solution solution;
    std::cout << solution.searchInsert(nums, tar) << std::endl;
    std::cin.get();
}