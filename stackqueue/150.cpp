#include <iostream>
#include <queue>
#include <stack>
// #include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        int a = 0, b = 0;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i].size() == 1 && tokens[i][0] >= '0' && tokens[i][0] <= '9') st.push(tokens[i][0] - '0');
            else if (tokens[i].size() > 1){
                int tmp = 0, t = 1;
                if (tokens[i][0] == '-'){
                    for (int j = tokens[i].size() - 1; j > 0; j--){
                        tmp += (tokens[i][j] - '0') * t;
                        t *= 10;
                    }
                    tmp = -tmp;
                    st.push(tmp);
                }
                else{
                    for (int j = tokens[i].size() - 1; j >= 0; j--){
                        tmp += (tokens[i][j] - '0') * t;
                        t *= 10;
                    }
                    // tmp = -tmp;
                    st.push(tmp);
                }

            }
            else if (tokens[i][0] == '+'){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (tokens[i][0] == '-'){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (tokens[i][0] == '*'){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if (tokens[i][0] == '/'){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b / a);
            }
        }

        return st.top();
    }
};


int main(){
    std::vector<std::string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution slt;
    int ans = slt.evalRPN(v);

    std::cin.get();
}