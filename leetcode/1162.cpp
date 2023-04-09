#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int res = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front(); q.pop();
                for (auto nxt : dirs) {
                    int x = top.first + nxt[0];
                    int y = top.second + nxt[1];
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }
            res++;
        }
        return (res == 0) ? -1 : res;
    }

};

int main() {
// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
    vector<vector<int>> grid = {
        // {1,0,0},
        // {0,0,0},
        // {0,0,0}
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    Solution* so = new Solution();
    int res = so->maxDistance(grid);
    cout << res << endl;

}