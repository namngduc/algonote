#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    set<pair<int, int>> BFS(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        set<pair<int, int>> visited;
        while (!q.empty()) {
            int m = q.front().first;
            int n = q.front().second;
            q.pop();
            if (visited.count({m, n})) {
                continue;
            }
            visited.insert({m, n});
            for (int idx = 0; idx < 4; idx++) {
                int x = m + dirs[idx][0];
                int y = n + dirs[idx][1];
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] >= grid[m][n]) {
                    q.push({x, y});
                } 
            }
        }
        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int M = heights.size(), N = heights[0].size();
        vector<vector<int>> pacific;
        vector<vector<int>> atlantic;
        for (int i = 0; i < M; i++) {
            pacific.push_back({0, i});
        }
        for (int i = 1; i < N; i++) {
            pacific.push_back({i, 0});
        }
        for (int i = 0; i < M; i++) {
            atlantic.push_back({i, N-1});
        }
        for (int i = 0; i < N-1; i++) {
            atlantic.push_back({M-1, i});
        }
        // for (auto x : pacific) {
        //     cout << "Pacific: "; 
        //     cout << x[0] << "," << x[1] << "\n";
        // }
        // for (auto x : atlantic) {
        //     cout << "Atlantic: "; 
        //     cout << x[0] << "," << x[1] << "\n";
        // }
        queue<pair<int, int>> q_pa, q_at;
        set<pair<int, int>> visited_pa, visited_at;
        for (vector<int> x : pacific) {
            q_pa.push({x[0], x[1]});
        }
        for (vector<int> x : atlantic) {
            q_at.push({x[0], x[1]});
        }
        visited_pa = BFS(heights, q_pa);
        visited_at = BFS(heights, q_at);
        for (pair<int, int> x : visited_pa) {
            if (visited_at.count({x.first, x.second})) {
                ans.push_back({x.first, x.second});
            }
        }
        // for (int i = 0; i < M; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << heights[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{1,2,2,3,5},
                                {3,2,3,4,4},
                                {2,4,5,3,1},
                                {6,7,1,4,5},
                                {5,1,1,2,4}};
    // vector<vector<int>> grid = {{1}};
    // [[2,1],[1,2]]
    Solution solution;
    vector<vector<int>> res = solution.pacificAtlantic(grid); 
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    // [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
}