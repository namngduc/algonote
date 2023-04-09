#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> paths;
        // cout << (int) sqrt(n) << endl;
        for (int i = (int) sqrt(n); i >= 1; i--) {
            paths.push_back(i*i);
        }
        // int res = 0;
        vector<int> memo(n+1, -1);
        int res = DP(paths, n, memo);
        // queue<vector<int>> q;
        // unordered_set<int> seen;
        // q.push({n, 0});
        // while (!q.empty()) {
        //     int size = q.size();
        //     vector<int> top = q.front();
        //     q.pop();
        //     int x = top[0], t = top[1];
        //     if (x == 0) {
        //         res = t;
        //         break;
        //     }
        //     for (int p : paths) {
        //         if (x >= p) {
        //             if (seen.find(x-p) != seen.end()) continue;
        //             q.push({x-p, t+1});
        //             seen.insert(x-p);
        //         }
        //     }
        // }
        // for (int n : paths) {
        //     cout << n << endl;
        // }
        return res;
    }
    int DP(vector<int>& paths, int x, vector<int>& memo) {
        if (x == 0) return 0;
        if (x < 0) return -1;
        if (memo[x] != -1) return memo[x];
        int res = INT_MAX;
        for (int num : paths) {
            int sub = DP(paths, x - num, memo);
            if (sub == -1) continue;
            res = min(res, 1 + sub);
        }
        memo[x] = res;
        return res;
        
    }
};

int main() {
// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
// For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
    int n = 7168;
    Solution* so = new Solution();
    int res = so->numSquares(n);
    cout << res << endl;
}