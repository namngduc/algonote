#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[35][1005];
    int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        // cout << MOD << endl;
        memset(memo, -1, sizeof(memo));
        return dp(n, k, target);
    }
    int dp(int n, int k, int target) {
        // cout << "(" << n << ", " << target << ")";
        if (n < 0 || target < 0) return 0;
        if (n == 0 && target == 0) return 1;
        if (memo[n][target] != -1) return memo[n][target];
        long long res = 0;
        for (int i = 1; i <= k; i++) {
            int subpro = dp(n-1, k, target - i);
            res += subpro;
        }
        memo[n][target] = res % MOD;
        return memo[n][target];
    }
};

int main() {
    int n = 30, k = 30, target = 500;
    // 222616187
    Solution so;
    int res = so.numRollsToTarget(n, k, target);
    cout << res;
}