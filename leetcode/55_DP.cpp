#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 0);
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = nums[i]; j >= 1; j--) {
                if (i+j >= N) continue;
                dp[i+j] |= dp[i];
                if (dp[i+j] && i+j == N-1) break;
            }
        }
        return dp[N-1];
    }
    //     int N = nums.size();
    //     vector<int> memo(N, -1);
    //     return DP(nums, 0, memo);
    // }

    // bool DP(vector<int>& nums, int i, vector<int>& memo) {
    //     if (i >= nums.size()) {
    //         return false;
    //     }
    //     if (i == nums.size()-1) {
    //         return true;
    //     }
    //     if (memo[i] != -1) return memo[i];
    //     bool res = false;
    //     for (int j = nums[i]; j >= 1; j--) {
    //         res |= DP(nums, i+j, memo);
    //         if (res) break;
    //     }
    //     memo[i] = res;
    //     return res;
    // }
};

int main() {
    // Input: nums = [2,3,1,1,4]
    // Output: true
    // Input: nums = [3,2,1,0,4]
    // Output: false
    vector<int> nums = {
        // 2, 3, 1, 1, 4
        // 3, 2, 1, 0, 4
        2,5,0,0
    };
    Solution* so = new Solution();
    bool res = so->canJump(nums);
    cout << (res == 0 ? "False" : "True") << endl;

}