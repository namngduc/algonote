#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        int res = 0;
        for (auto& con : connections) {
            adj[con[0]].push_back({con[1], 1});
            adj[con[1]].push_back({con[0], 0});
        }
        vector<bool> visited(n);
        visited[0] = true;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int top = q.front(); q.pop();
            for (auto& [nxt, sign] : adj[top]) {
                if (!visited[nxt]) {
                    res += sign;
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        return res;
    }
};


int main() {
    // Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
    // Output: 3
    // Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
    // Output: 2
    vector<vector<int>> connections = {
        {0,1},{1,3},{2,3},{4,0},{4,5}
    };
    int n = 6;
    Solution* so = new Solution();
    int res = so->minReorder(n, connections);
    cout << res << endl;
}