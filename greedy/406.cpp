#include <iostream>
#include <vector>
#include <list>
#include "algorithm"

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue (std::vector<std::vector<int>>& people) {
        int size = people.size();
        if (size == 1) return people;

        std::list<std::vector<int> > res;
        auto cmp = [](const std::vector<int>& vec1, const std::vector<int>& vec2) {
            if (vec1[0] != vec2[0]) return vec1[0] > vec2[0];
            else return vec1[1] < vec2[1];
        };
        std::sort(people.begin(), people.end(), cmp);

        for (int i = 0; i < size; ++i) {
            auto it = res.begin();
            int j = people[i][1];
            while (j--) { it++; }
            res.insert(it, people[i]);
            
        }
        return std::vector<std::vector<int> >(res.begin(), res.end());
    }
};

int main() {
    std::vector<std::vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution slt;
    slt.reconstructQueue(people);
    std::cin.get();
}