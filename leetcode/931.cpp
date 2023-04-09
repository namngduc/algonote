#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int N = matrix.size();
        vector<vector<int>> dp(N+2, vector<int>(N+2, INT_MAX));
        for (int i = 1; i <= N; i++) {
            dp[1][i] = matrix[0][i-1];
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // cout << matrix[i-1][j-1] << " \n"[j==N];
                // cout << dp[i-1][j-1] << "-" << dp[i-1][j] << "-" << dp[i-1][j+1] << endl;
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + matrix[i-1][j-1];
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << dp[i][j] << " \n"[j==N];
            }
        }
        for (int i = 1; i <= N; i++) {
            res = min(res, dp[N][i]);
        }
        return res;
    }
    //     vector<vector<int>> memo(N+1, vector<int> (N+1, -1));
    //     for (int i = 0; i < matrix[0].size(); i++) {
    //         // cout << DP(matrix, 0, i) << endl;
    //         res = min(res, DP(matrix, 0, i, memo));
    //     }
    //     return res;
    // }
    // int DP(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& memo) {
    //     if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
    //         return INT_MAX;
    //     }
    //     if (x == grid.size() - 1) {
    //         return grid[x][y];
    //     }
    //     if (memo[x][y] != -1) return memo[x][y];
    //     int res = grid[x][y] + min({DP(grid, x+1, y, memo), DP(grid, x+1, y-1, memo), DP(grid, x+1, y+1, memo)});
    //     memo[x][y] = res;
    //     return res;
    // }
};

int main() {
    // Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    // Output: 13
    // Input: matrix = [[-19,57],[-40,-5]]
    // Output: -59
    vector<vector<int>> matrix = {
        {2,1,3},{6,5,4},{7,8,9}
        // {-19,57},{-40,-5}
    };
    Solution* so = new Solution();
    int res = so->minFallingPathSum(matrix);
    cout << res << endl;
}