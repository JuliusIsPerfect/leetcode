#include<iostream>
#include<unordered_set>

class Solution {
public:
    bool isHappy(int n) {

        std::unordered_set<int> set, sum;
        int tmp;
        while(1){
            if (n == 1) return true;
            set.clear();
            tmp = 0;
            while (n > 9){
                tmp += (n % 10) * (n % 10);

                n = n / 10;

            }
            tmp += n*n;
            if (tmp == 1) return true;

            if (sum.find(tmp) == sum.end()){
                sum.insert(tmp);
                n = tmp;
            }
            else return false;
        }

    }
};

int main(){
    int n;
    std::cin >> n;
    Solution solution;
    bool ans = solution.isHappy(n);

    std::cin.get();
}