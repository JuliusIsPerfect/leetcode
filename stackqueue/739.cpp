#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> temp;
        std::stack<int> idx;
        std::vector<int> res(temperatures.size());
        temp.push(temperatures[0]);
        idx.push(0);
        // int max = temperatures[0];

        for (int i = 1; i < temperatures.size(); ++i) {
            while (!temp.empty() && temperatures[i] > temp.top()) {
                res[idx.top()] = i - idx.top();
                temp.pop();
                idx.pop();
            }
            temp.push(temperatures[i]);
            idx.push(i);
        }

        while (!idx.empty()) {
            res[idx.top()] = 0;
            idx.pop();
        }
        return  res;
    }
};

int main() {
    std::vector<int> temperatures = {55,38,53,81,61,93,97,32,43,78};
    Solution slt;
    auto res = slt.dailyTemperatures(temperatures);
    std::cin.get();
}