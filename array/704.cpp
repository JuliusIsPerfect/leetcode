#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
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
        return -1;
    }
};

int main(){
    std::vector<int> nums;
    nums = {-1,0,3,5,9,12};
    // for(int i=0; i<nums.size();i++)
    //     std::cout << nums[i] << std::endl;
    int tar = 9;
    Solution solution;
    std::cout << solution.search(nums, tar);
    std::cin.get();
}