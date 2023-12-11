#include <iostream>
#include <vector>
class Solution {
public:
    int head = 0;
    int removeElement(std::vector<int>& nums, int val) {
        int last = nums.size() - 1, tmp, cnt = 0, first;
        for (int i = 0; i <nums.size(); i++)
            if (nums[i] == val) cnt++;
        while(head <= last - cnt){
            if(nums[head] == val){
                first = head+1;
                while(1){
                    if (nums[first] != val) break;
                    first ++;
                }
                tmp = nums[first];
                nums[first] = val;
                nums[head] = tmp;
                head++;
            }
            else {head++;continue;}

        }
        return head;
    }
};

int main(){
    std::vector<int> num = {0,1,2,2,3,0,4,2};// 0 1 2 2 3 0 4 2
    int val;
    std::cin >> val;
    // std::cout << "val:" << val << std::endl;
    Solution solution;
    int ans = solution.removeElement(num, val);
    std::cout << ans << std::endl;
    for (int i = 0; i < solution.head; i++)
        std::cout << num[i] << " ";
    std::cout << std::endl;
    std::cin.get();
}


//每个人建立分支管理自己的部分（推荐）
//or私下分工完成整个项目
//每个人至少一次提交记录