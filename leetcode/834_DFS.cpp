#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> count, res;
    void DFS(int u, int p = -1) {
        for (int v : graph[u]) {
            if (v == p) continue;
            DFS(v, u);
            count[u] += count[v];
            res[u] += res[v] + count[v];
        }
        count[u] += 1;
    }
    void DFS1(int u, int n, int p = -1){
        for (int v : graph[u]) {
            if (v == p) continue;
            res[v] = res[u] - count[v] + n - count[v];
            DFS1(v, n, u);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for (auto &u : edges) {
            graph[u[0]].push_back(u[1]);
            graph[u[1]].push_back(u[0]);
        };
        count.resize(n);
        res.resize(n);
        DFS(0);
        DFS1(0, n);
        // for (int i : res) cout << i << " ";
        // cout << "\n";
        // for (int i : count) cout << i << " ";
        // cout << endl;
        return res;
    }
};

int main() {
    // Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
    // Output: [8,12,6,10,10,10]
    // Input: n = 1, edges = []
    // Output: [0]
    // Input: n = 2, edges = [[1,0]]
    // Output: [1,1]
    int n = 6;
    vector<vector<int>> edges = {
        {0,1},{0,2},{2,3},{2,4},{2,5}
    };
    Solution* so = new Solution();
    vector<int> res = so->sumOfDistancesInTree(n, edges);
    for (int n : res) cout << n << " ";
    cout << "\n";
}