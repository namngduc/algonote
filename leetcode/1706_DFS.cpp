#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> res(N, 0);
        for (int c = 0; c < N; c++) {
            res[c] = DFS(grid, 0, c, M, N);
        }
        return res;

    }
    int DFS(vector<vector<int>>& grid, int x, int y, int M, int N) {
        if (x == M) return y;
        if (checkValid(x, y, M, N)) {
            if (grid[x][y] == 1) {
                if (checkValid(x, y+1, M, N) && grid[x][y+1] == 1) {
                    return DFS(grid, x+1, y+1, M, N);
                }
            }
            else {
                if (checkValid(x, y-1, M, N) && grid[x][y-1] == -1) {
                    return DFS(grid, x+1, y-1, M, N);
                }
            }
        }
        return -1;

    }
   bool checkValid(int x , int y, int M, int N) {
    return (x >= 0 && x < M && y >= 0 && y < N);
   }
}; 

int main() {
    vector<vector<int>> grid = {
    //    { 1,  1,  1,  -1,  -1},
    //    { 1,  1,  1,  -1,  -1},
    //    {-1, -1, -1,   1,   1},
    //    { 1,  1,  1,   1,  -1},
    //    {-1, -1, -1,  -1,  -1}
    {1,1,1,1,1,1},
    {-1,-1,-1,-1,-1,-1},
    {1,1,1,1,1,1},
    {-1,-1,-1,-1,-1,-1}
    };
    // [1,-1,-1,-1,-1]
    Solution* so = new Solution();
    vector<int> res = so->findBall(grid);
    for (int n : res) {
        cout << n << " ";
    }
    cout << endl;
}