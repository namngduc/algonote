#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, size;
    UnionFind(int k) {
        parent.resize(k+1);
        size.resize(k+1);
        for (int i = 1; i < k+1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        if (size[rootP] >= size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    bool connected(int p, int q) {
        int u = find(p);
        int v = find(q);
        return u == v;
    }
};


class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        UnionFind* UF = new UnionFind(n);
        for (auto road : roads) {
            UF->union_set(road[0], road[1]);
        }
        for (auto road : roads) {
            if (UF->connected(1, road[0])) {
                ans = min(ans, road[2]);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int BFS(int n, vector<vector<pair<int, int>>>& adj) {
//         int ans = INT_MAX;
//         vector<bool> visited(n+1);
//         queue<int> q;
//         q.push(1);
//         visited[1] = true;
        
//         while(!q.empty()) {
//             int top = q.front(); q.pop();
//             for (auto& edge : adj[top]) {
//                 ans = min(ans, edge.second);
//                 if (!visited[edge.first]) {
//                     visited[edge.first] = true;
//                     q.push(edge.first);
//                 }
//             }
//         }
//         return ans;
//     }

//     int minScore(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int, int>>> adj(n+1);
//         for (auto road : roads) {
//             adj[road[0]].push_back({road[1], road[2]});
//             adj[road[1]].push_back({road[0], road[2]});
//         }
//         return BFS(n, adj);    
//     }
// };


int main() {
    // Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
    // Output: 5
    // Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
    // Output: 2
    vector<vector<int>> roads = {
        {1,2,9},{2,3,6},{2,4,5},{1,4,7}
    };
    int n = 4;
    Solution* so = new Solution();
    int res = so->minScore(n, roads);
    cout << res << endl;
}