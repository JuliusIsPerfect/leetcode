#include <iostream>
#include <vector>
#include "algorithm"

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue
        (std::vector<std::vector<int>>& people) {
        int size = people.size();
        if (size == 1) return people;

        std::vector<std::vector<int>> que(size);
        std::sort(people.begin(), people.end());

        for (int i = 0; i < size; ++i) {
            que.insert(people.begin() + people[i][1], people[i]);
        }

        return que;
    }
};

int main() {
    std::vector<std::vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution slt;
    slt.reconstructQueue(people);
    std::cin.get();
}