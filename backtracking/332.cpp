#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> result;
    std::vector<std::string> path;
    std::vector<bool> used;

    bool backtracking(std::vector<std::vector<std::string>>& tickets) {
        if (path.size() > tickets.size()) {
            if(result.empty() || result > path) result = path;
            return true;
        }

        for (int i = 0; i < tickets.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && tickets[i] == tickets[i - 1] && !used[i -1]) continue;
            if (tickets[i][0] == path.back()) {
                used[i] = true;
                path.emplace_back(tickets[i][1]);
                // tickets已经排过序，所以这一层搜到的第一个结果就是满足字典序最小的，直接在这return
                if(backtracking(tickets)) return true;
                path.pop_back();
                used[i] = false;
            }
            
        }

        return false;
    }

    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        if (tickets.size() == 1) return {tickets[0][0], tickets[0][1]};
        used = std::vector<bool>(tickets.size(), false);
        std::sort(tickets.begin(), tickets.end());
        path.emplace_back("JFK");
        backtracking(tickets);
        return result;
    }
};

int main() {
    std::vector<std::vector<std::string>> tickets;
    // tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution slt;
    slt.findItinerary(tickets);

    std::cin.get();
}