#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[5005][2];
    int maxProfit(vector<int>& prices) {
    //     int N = prices.size();
    //     vector<vector<int>> dp(N+2, vector<int>(2, 0));
    //     for (int day = N+1; day>=0; day--) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             int ans;
    //             if (day >= N) {
    //                 ans = 0;
    //             }
    //             else {
    //                 int ans1 = dp[day+1][buy];
    //                 int ans2 = 0;
    //                 if (buy) {
    //                     ans2 = -prices[day] + dp[day+1][0]; 
    //                 }
    //                 else {
    //                     ans2 = prices[day] + dp[day+2][1];
    //                 }
    //                 ans = max(ans1, ans2);
    //             }
    //             dp[day][buy] = ans;
    //         }
    //     }
    //     return dp[0][1];
    // }
        int N = prices.size();
        memset(&memo[0][0], -1, sizeof(memo));
        return DP(prices, 0, true);
    }
    int DP(vector<int>& prices, int day, bool buy) {
        if (day >= prices.size()) return 0;
        if (memo[day][buy] != -1) return memo[day][buy];
        int ans1 = DP(prices, day+1, buy);
        int ans2 = 0; 
        if (buy) {
            ans2 = -prices[day] + DP(prices, day+1, false);
        }
        else {
            ans2 = prices[day] + DP(prices, day+2, true);
        }
        int res = max(ans1, ans2);
        memo[day][buy] = res;
        return res;
    }
};


int main() {
    // Input: prices = [1,2,3,0,2]
    // Output: 3
    // Explanation: transactions = [buy, sell, cooldown, buy, sell]
    vector<int> prices = {
        1,2,3,0,2
    };
    Solution* so = new Solution();
    int res = so->maxProfit(prices);
    cout << res << endl;
}
