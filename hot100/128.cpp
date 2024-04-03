#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::unordered_map<int, int> fa;
    std::unordered_map<int, int> cnt;

    int find(int x) {
        if (fa[x] == x) {
            return fa[x];
        }
        fa[x] = find(fa[x]);
        return fa[x];
    }    

    void merge(int x, int y) {
        int fax = find(x), fay = find(y);
        if (fax != fay) {
            fa[y] = fa[x];
            cnt[fax] += cnt[fay];
        }
        
    }

    int longestConsecutive(std::vector<int>& nums) {
        for (auto &i : nums) {
            fa[i] = i;
            cnt[i] = 1;
        }

        for (auto &[i, j] : fa) {
            if (fa.find(i - 1) != fa.end()) {
                merge(i - 1, i);
            }
            if (fa.find(i + 1) != fa.end()) {
                merge(i, i + 1);
            }
        }

        int res = 0;
        for (auto &i : cnt) {
            res = (i.second > res) ? i.second : res;
        }
        return res;
    }
};