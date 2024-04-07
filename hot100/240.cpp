#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto &row : matrix) {
            auto find = lower_bound(row.begin(), row.end(), target);
            if (find != row.end() && *find == target) {
                return true;
            }
        }
        return false;
    }
};