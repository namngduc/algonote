#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph;
        graph.resize(n);
        vector<int> ans(n, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        DFS(0, labels, graph, ans);
        return ans;

    }
    vector<int> DFS(int node, string& labels, vector<vector<int>>& graph, vector<int>& ans) {
        ans[node] = 1;
        vector<int> cnt(26, 0);
        cnt[labels[node] - 'a']++;
        for (int i = 0; i < graph[node].size(); i++) {
            int nxt = graph[node][i];
            if (ans[nxt]) continue;
            vector<int> tmp = DFS(nxt, labels, graph, ans);
            for (int j = 0; j < 26; j++) {
                if (tmp[j] == 0) continue;
                cnt[j] += tmp[j];
            }
        }
        ans[node] = cnt[labels[node] - 'a'];
        return cnt;
    }
};

int main() {
    // Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
    // Output: [2,1,1,1,1,1,1]
    // Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
    // Output: [4,2,1,1]
    // Input: n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
    // Output: [3,2,1,1,1]
    vector<vector<int>> edges = {
        // {0,1},{0,2},{1,4},{1,5},{2,3},{2,6}
        // {0,1},{1,2},{0,3}
        {0,1},{0,2},{1,3},{0,4}
    };
    string labels = "aabab";
    int n = 5;
    Solution* so = new Solution();
    vector<int> res = so->countSubTrees(n, edges, labels);
    for (int n : res) cout << n << " ";
    cout << endl;
}