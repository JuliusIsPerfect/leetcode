#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // std::unordered_map<int, int> map;
        std::unordered_set<int> rowset, colset;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rowset.insert(i);
                    colset.insert(j);
                }
            }
        }

        for (auto &row : rowset) {
            for (int j = 0; j < n; ++j){
                matrix[row][j] = 0;
            }
        }
        for (auto &col : colset) {
            for (int i = 0; i < m; ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};