#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> array(n);
        // std::vector<std::vector<int>> mat(n,std::vector<int>(n));
        if (!n) {
            return array;
        }
        for (int i = 0; i<n; i++)
            array[i] = std::vector<int> (n);
        int r = 1, idx = 0;
        while(1){
            if(idx == n * n) break;
            for (int i = r - 1; i <= n - r; i++){
                idx++;
                array[r - 1][i] = idx;
            }
            if(idx == n * n) break;
            for (int i = r; i <= n - r; i++){
                idx++;
                array[i][n-r] = idx;
            }
            if(idx == n * n) break;
            for (int i = n - r - 1; i >= r - 1; i--){
                idx++;
                array[n-r][i] = idx;
            }
            if(idx == n * n) break;
            for (int i = n - r - 1; i >= r; i--){
                idx++;
                array[i][r - 1] = idx;
            }
            r++;
        }
    return array;
    }
};

int main(){
    // std::vector<std::vector<int>> array = {{1,2,3},{8,9,4},{7,6,5}};
    // std::vector<std::vector<int>> array = {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    int n;
    std::cin >> n;
    Solution solution;
    auto ans = solution.generateMatrix(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << ans[i][j] << " ";
        std::cout << std::endl;
    }
        
    std::cin.get();
}
/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/
