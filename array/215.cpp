#include<iostream>
#include <queue>
#include<vector>

/*
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> que;
        for (auto &i : nums) {
            que.push(i);
        }
        while (--k) {
            que.pop();
        }
        return que.top();
    }
};
*/
class Solution {
public:
    void modifyheap(std::vector<int>& nums, int root, int heapsize) {
        int l = 2 * root + 1, r = 2 * root + 2;
        int cur = root;
        if (l < heapsize && nums[l] > nums[cur]) {
            cur = l;
        }
        if (r < heapsize && nums[r] > nums[cur]) {
            cur = r;
        }
        if (cur != root) {
            std::swap(nums[root], nums[cur]);
            modifyheap(nums, cur, heapsize);
        }
    }

    void buildheap(std::vector<int>& nums, int heapsize) {
        for (int i = heapsize / 2; i >= 0; --i) {
            modifyheap(nums, i, heapsize);
        }
    }

    int findKthLargest(std::vector<int>& nums, int k) {
        int res = 0;
        int size = nums.size();
        buildheap(nums, size);
        while (--k) {
            std::swap(nums[0], nums[size - 1]);
            modifyheap(nums, 0, --size);
        }
        return nums[0];
    }
};