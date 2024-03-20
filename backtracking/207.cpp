#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses);
        vector<vector<int>> towards(numCourses);
        queue<int> que;

        for (auto &pair : prerequisites) {
            ++in[pair[1]];
            towards[pair[0]].emplace_back(pair[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) que.push(i);
        }

        int cnt = 0;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            ++cnt;
            
            for (auto iter : towards[cur]) {
                --in[iter];
                if (in[iter] == 0) que.push(iter);
            }
        }

        return cnt == numCourses;
    }
};