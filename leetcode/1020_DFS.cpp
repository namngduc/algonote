#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void DFS(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        for (auto& v : dirs) {
            int i = x + v[0];
            int j = y + v[1];
            DFS(i, j, grid);
        }    
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        for (int i = 0; i < M; i++) {
            if (grid[i][0] == 1) {
                DFS(i, 0, grid);
            }
            if (grid[i][N-1] == 1) {
                DFS(i, N-1, grid);
            }
        }
        for (int j = 0; j < N; j++) {
            if (grid[0][j] == 1) {
                DFS(0, j, grid);
            }
            if (grid[M-1][j] == 1) {
                DFS(M-1, j, grid);
            }
        }
        int cnt = 0;
        for (int i = 1; i < M-1; i++) {
            for (int j = 1; j < N-1; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


int main() {
// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
    vector<vector<int>> grid = {
        // {0,0,0,0},
        // {1,0,1,0},
        // {0,1,1,0},
        // {0,0,0,0}
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    Solution* so = new Solution();
    int res = so->numEnclaves(grid);
    cout << res << endl;
}