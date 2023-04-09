#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int N = graph.size();
        queue<pair<int, vector<int>>> queue;
        queue.push({0, {0}});
        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();
            if (top.first == N-1) {
                res.push_back(top.second);
            }
            else {
                for (int nxt : graph[top.first]) {
                    top.second.push_back(nxt);
                    queue.push({nxt, top.second});
                    top.second.pop_back();
                }
            }
        }
        return res;
    }
    
};

int main() {
    // Input: graph = [[1,2],[3],[3],[]]
    // Output: [[0,1,3],[0,2,3]]
    // Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
    // Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    vector<vector<int>> graph = {
        // {1, 2}, {3}, {3}, {}
        {4, 3, 1}, {3, 2, 4}, {3}, {4}, {}
    };
    Solution* so = new Solution();
    vector<vector<int>> res = so->allPathsSourceTarget(graph);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " \n"[j==res[i].size()-1];
        }
    }

}