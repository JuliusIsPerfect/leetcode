#include<iostream>
#include<unordered_map>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2,
                     std::vector<int>& nums3, std::vector<int>& nums4) {
        int cnt = 0;
        /*
        std::unordered_map<int, int> map1, map2, map3, map4;
        for (int i = 0; i < nums1.size(); i++){
            if (map1.find(nums1[i]) == map1.end()) map1.insert({nums1[i],0});
            else map1[nums1[i]];
        }
        
        for (int i = 0; i < nums2.size(); i++) map2.insert({nums2[i],i});
        for (int i = 0; i < nums3.size(); i++) map3.insert({nums3[i],i});
        for (int i = 0; i < nums4.size(); i++) map4.insert({nums4[i],i});
        */

        std::unordered_map<int, int> sum;
        
        for (int i = 0; i < nums1.size(); i++)
            for(int j = 0; j < nums2.size(); j++)
                sum[nums1[i] + nums2[j]]++;
        

        for (int i = 0; i < nums3.size(); i++)
            for(int j = 0; j < nums4.size(); j++)
            if(sum.find(-nums3[i]-nums4[j]) != sum.end()) cnt += sum[-nums3[i]-nums4[j]];
        

        return cnt;   
    }
};

int main(){
    


    std::cin.get();
}