#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string ipstring;
    std::vector<std::string> result;

    void dfs(std::string s, int partition){
        if (partition == 4){
            if (s.size() > 0) {
                // ipstring.clear();
                return;
            }
            
            // if (ipstring.back() == '.') ipstring.pop_back();
            result.push_back(ipstring);
            // ipstring.clear();                
            return;
        }

        for (int i = 1; i <= 3 && i <= s.size(); i++) {
            std::string pre = s.substr(0, i);
            int pre_num = std::stoi(pre);
            if ((pre[0] == '0' && pre.size() > 1) || pre_num > 255) break;
            ipstring += pre + ".";
            dfs(s.substr(i), partition + 1);
            ipstring = ipstring.substr(0, ipstring.size() - pre.size() - 1);
        }
    }

    std::vector<std::string> restoreIpAddresses(std::string s) {
        if (s.size() < 4 || s.size() > 12) return {};
        // ipstring = s;
        dfs(s, 0);
        for (auto& it : result)
            it.pop_back();
        return result;
    }
};

int main(){
    std::string s = "101023";
    Solution slt;
    slt.restoreIpAddresses(s);
    std::cin.get();
}