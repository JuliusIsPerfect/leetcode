#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> ans;
        if (nums.size() < 4) return ans;
        int l, r;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 1; i++){
            if (nums[i] > target && nums[i] >= 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j <= nums.size() - 1; j++){
                if (nums[i] + nums[j] > target && nums[j] >= 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                l = j + 1, r = nums.size() - 1;
                while (l < r){
                    // if (nums[i] + nums[j] + nums[l] + nums[r] == target
                        // && nums[l] != nums[l-1] && nums[r] != nums[r+1])
                    if ((long)nums[i] + nums[j] + nums[l] + nums[r] > target) {
                        r--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[l] + nums[r]  < target){
                        l++;
                    }
                        
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l + 1])
                            l++;
                        while(l < r && nums[r] == nums[r - 1])
                            r--;
                        l++;
                        r--;
                    }

                }
            }

        }

        return ans;
    }
};

int main(){
    std::vector<int> nums{-3,-1,0,2,4,5}; //-2,-1,0,0,1,2
    int target = 1;
    // std::cin >> target;
    Solution solution;
    auto ans = solution.fourSum(nums, target);

    
    std::cin.get();
}