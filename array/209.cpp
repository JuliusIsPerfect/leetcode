#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int l = 0, flag = 0;
        int sum = 0, end = 0, minlen = 1e5;
        while (sum < target and (end <= nums.size()-1)){
            sum += nums[end];
            end++;
        }
        if(sum < target) return 0;
        else{
            minlen = end - l;
            flag = 1;
        }

        while (l <= nums.size() - 1 and end < nums.size()){
            if (sum - nums[l] >= target){
                l++;
                minlen--;
                sum = sum - nums[l];
                continue;
            }
            else{
                if (end+1 <= nums.size()-1){
                    sum = sum - nums[l] + nums[end+1];

                }
                else break;
            }

        }
        return minlen;
    }
};

int main(){
    int tar;
    std::cin >> tar;
    std::vector<int> num = {2,3,1,2,4,3};
    Solution solution;
    int ans = solution.minSubArrayLen(tar, num);
    std::cout << ans << std::endl;
    std::cin.get();
}