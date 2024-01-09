#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if (st.empty()) st.push(s[i]);
            else if (st.top() == s[i]){
                st.pop();
                continue;
            }
            else st.push(s[i]);

        }
        std::string s1;
        int stlen = st.size();
        for (int i = 0; i < stlen; i++) {
            s1.push_back(st.top());
            st.pop();
        }
        std::reverse(s1.begin(), s1.end());
        return s1;
    }
};

int main(){
    std::string s = "azxxzy";
    Solution slt;
    std::string ans = slt.removeDuplicates(s);

    std::cin.get();
}