#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::unordered_map<int, int> fa;
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, int> cnt;

    int find(int x) {
        if (fa[x] == x) {
            return x;
        }
        else {
            fa[x] = find(fa[x]);
            return fa[x];
        }
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) fa[x] = y, cnt[y] += cnt[x];
    }

    int longestConsecutive(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // visited[nums[i]] = false;
            fa[nums[i]] = nums[i];
            cnt[nums[i]] = 1;
            // if (cnt.find(nums[i]) == cnt.end()) cnt[nums[i]] = 0;
            // else ++cnt[nums[i]];
        }

        for (int i = 0; i < nums.size(); ++i) {
            // if (visited[nums[i]]) continue;

            if (fa.find(nums[i] - 1) != fa.end()) {
                merge(nums[i], nums[i] - 1);
                // visited[nums[i]] = true;
                // visited[nums[i] - 1] = true;
            }
            // if (fa.find(nums[i] + 1) != fa.end()) {
            //     merge(nums[i] + 1, nums[i]);
            //     // visited[nums[i]] = true;
            //     // visited[nums[i] + 1] = true;
            // }
            // visited[nums[i]] = true;
        }

        int res = 0;
        for (auto &num : nums) {
            res = (res >= cnt[num]) ? res : cnt[num];
        }
        return res;
    }
};

int main() {
    std::vector<int> nums{7, -2, 9,  9, 1, 9,  8, -4, 6,  -6, -6, 4, 1,  3, 6,
                          3, 5,  -2, 3, 4, -6, 1, 5,  -9, 6,  1,  2, -2, 1};
    Solution slt;
    int res = slt.longestConsecutive(nums);
    std::cin.get();
}