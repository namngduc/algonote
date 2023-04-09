#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N+1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < N; i++) {
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        // for (int i = 0; i <= N; i++) {
        // cout << dp[i] << " ";
        // }
        return dp[N];
    }
    //     vector<int> memo(N, -1);
    //     return DP(nums, 0, memo);
    // }
    // int DP(vector<int>& nums, int i, vector<int>& memo) {
    //     if (i >= nums.size()) {
    //         return 0;
    //     }
    //     if (memo[i] != -1) return memo[i];
    //     int res = max(nums[i] + DP(nums, i+2, memo), DP(nums, i+1, memo));
    //     memo[i] = res;
    //     return res;
    // }
};

int main() {
    // Input: nums = [1,2,3,1]
    // Output: 4
    // Input: nums = [2,7,9,3,1]
    // Output: 12
    vector<int> nums = {
        1, 2, 3, 1
        // 2, 7, 9, 3, 1
        // 2, 1, 1, 2
        // 2, 1
    };
    Solution* so = new Solution();
    int res = so->rob(nums);
    cout << res << endl;
}