#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
    int l = 0, end = 0, flag = 0;
    int sum = 0, minlen = 1e5;
        while (end <= nums.size() - 1){
            sum += nums[end];
            if (sum >= target){
                flag = 1;
                break;
            }
            end++;
        }
        if (!flag) return 0;
        else{
            minlen = end - l + 1;
            while(l <= nums.size()-1 && end <= nums.size()-1){
                if (sum - nums[l] >= target){
                    sum = sum - nums[l];
                    l++;
                    minlen--;
                }
                else{
                    if (end+1 <= nums.size()-1){
                        end++;
                        
                        sum = sum - nums[l] + nums[end];
                        l++;
                    }
                    else break;

                }
            }
            if (end - l + 1 < minlen) minlen = end - l + 1;
            return minlen;

        }

    }
};

int main(){
    std::vector<int> num = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    int tar;
    std::cin >> tar;
    Solution solution;
    int ans = solution.minSubArrayLen(tar, num);
    std::cout << ans << std::endl;
    std::cin.get();
}