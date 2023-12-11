#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int idx=0, len = nums.size() , tag = 0;
        std::vector<int> tmp;
        // int arr[20000];
        if (nums[len - 1] <= 0){
            for (int i = len - 1; i >= 0; i--)
                tmp.push_back(nums[i] * nums[i]);
            nums = tmp;
            return nums;
        }
        if(nums[0] >= 0){
            for (int i = 0; i <= len -1; i++)
                tmp.push_back(nums[i] * nums[i]);
            nums = tmp;
            return nums;
        }
        while(idx < len){
            if (nums[idx] == 0) break;
            if (nums[idx] < 0 and nums[idx + 1] > 0) {
                tag = 1;
                break;
            }
            idx++;
        }

        if (tag) { //没有0
            int idxr = idx + 1;
                        while(idx >= 0 && (idxr <= len - 1)){
                if (-nums[idx] <= nums[idxr]) {
                    tmp.push_back(nums[idx] * nums[idx]);
                    idx--;
                }
                else{
                    tmp.push_back(nums[idxr] * nums[idxr]);
                    idxr++;
                }
            }
            if(idx >= 0){
                while(idx >= 0){
                    tmp.push_back(nums[idx] * nums[idx]);
                    idx--;
                }
            }
            else{
                while (idxr <= len -1){
                    tmp.push_back(nums[idxr] * nums[idxr]);
                    idxr++;
                }
            }
        }
        else{ //有0
            int idxr = idx + 1;
            while(idx >= 0 && (idxr <= len - 1)){
                if (-nums[idx] <= nums[idxr]) {
                    tmp.push_back(nums[idx] * nums[idx]);
                    idx--;
                }
                else{
                    tmp.push_back(nums[idxr] * nums[idxr]);
                    idxr++;
                }
            }
            if(idx >= 0){
                while(idx >= 0){
                    tmp.push_back(nums[idx] * nums[idx]);
                    idx--;
                }
            }
            else{
                while (idxr <= len -1){
                    tmp.push_back(nums[idxr] * nums[idxr]);
                    idxr++;
                }
            }
        }
        nums = tmp;
        // for (idx)
        return nums;
    }
};


int main(){
    std::vector<int> num = {-1,2,2};
    Solution solution;
    solution.sortedSquares(num);
    for (int i = 0;i<=num.size() - 1;i++)
        std::cout << num[i] << " ";
    std::cout << std::endl;
    std::cin.get();
}