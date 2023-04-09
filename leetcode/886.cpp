#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;
        vector<int> color(n+1, -1);
        for (auto &d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (isBipartite(graph, i, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(unordered_map<int, vector<int>>& graph, int src, vector<int>& color) {
        queue<int> queue;
        queue.push(src);
        color[src] = 1;
        while (!queue.empty()) {
            int top = queue.front();
            queue.pop();
            for (int next : graph[top]) {
                if (color[next] == -1) {
                    color[next] = 1 - color[top];
                    queue.push(next);
                }
                if (color[next] == color[top]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    // Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
    // Output: true
    // Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
    // Output: false
    // Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
    // Output: false
    int n = 5;
    vector<vector<int>> dislikes = {
        // {1,2},{1,3},{2,4}
        // {1,2},{1,3},{2,3}
        // {1,2},{2,3},{3,4},{4,5},{1,5}
        {1,2},{3,4},{4,5},{3,5}
    };
    Solution* so = new Solution();
    bool res = so->possibleBipartition(n, dislikes);
    cout << (res == 0 ? "False" : "True") << endl;
}