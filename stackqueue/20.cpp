#include <iostream>
#include <queue>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        int slen = s.size();

        // if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;

        for(int i = 0; i < slen; i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
                continue;
            }
            else if (s[i] == ')'){
                if (st.empty()) return false;
                if (st.top() == '(') {
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if (s[i] == ']'){\
                if (st.empty()) return false;
                if (st.top() == '[') {
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if (s[i] == '}'){
                if (st.empty()) return false;
                if (st.top() == '{') {
                    st.pop();
                    continue;
                }
                else return false;
            }

        }
        
        if (st.empty()) return true;

        return false;
    }
};

int main(){
    std::string s("(])");
    Solution slt;
    bool ans = slt.isValid(s);

    std::cin.get();
}