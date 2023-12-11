#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralArray(std::vector<std::vector<int>>& array) {
        if (array.empty()) {
            std::vector<int> ans0;
            return ans0;
        }
        int m = array.size(), n = array[0].size() , r = 1, idx = 0;
        std::vector<int> ans(m * n);
        while(1){
            if(idx == m * n) break;
            for (int i = r - 1; i <= n - r; i++){
                ans[idx] = array[r - 1][i];
                idx++;
            }
            if(idx == m * n) break;
            for (int i = r; i <= m - r; i++){
                ans[idx] = array[i][n-r];
                idx++;
            }
            if(idx == m * n) break;
            for (int i = n - r - 1; i >= r - 1; i--){
                ans[idx] = array[m-r][i];
                idx++;
            }
            if(idx == m * n) break;
            for (int i = m - r - 1; i >= r; i--){
                ans[idx] = array[i][r - 1];
                idx++;
            }
            r++;
        }
    return ans;
    }
};

int main(){
    // std::vector<std::vector<int>> array = {{1,2,3},{8,9,4},{7,6,5}};
    // std::vector<std::vector<int>> array = {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    std::vector<std::vector<int>> array = {};
    int m = array.size(), n = array[0].size();
    Solution solution;
    auto ans = solution.spiralArray(array);
    for (int i = 0; i < m*n; i++)
        std::cout << ans[i] << " ";
    std::cin.get();
}
/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/