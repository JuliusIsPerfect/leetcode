#include <iostream>
#include <vector>

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        std::vector<int> F{0,1};

        for (int i = 2; i <= n; ++i) {
            F.emplace_back(F[i - 1] + F[i - 2]);    
        }

        return F[n];
    }
};

