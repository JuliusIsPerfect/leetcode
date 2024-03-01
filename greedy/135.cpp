#include <iostream>
#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        int sum = 0;
        std::vector<int> res(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) res[i] = res[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                res[i] = ((res[i + 1] + 1) > res[i]) ? res[i + 1] + 1 : res[i];
        }
        for (auto& it : res) sum += it;

        return sum;
    }
};

int main() {
    std::vector<int> ratings{1,0,10,6,3,1,6,4};
    Solution slt;
    slt.candy(ratings);

    std::cin.get();
}