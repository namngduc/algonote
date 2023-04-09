#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memo[1005][1005];
    int ans = INT_MIN;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // memset(memo, -1, sizeof(memo));
        // int res = DP(nums1, nums2, 0, 0);
        // return ans;
        int M = nums1.size(), N = nums2.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                    ans = max(ans, dp[i+1][j+1]);
                }
                else 
                    dp[i+1][j+1] = 0;
            }
        }
        return ans;
    }
    // int DP(vector<int>& nums1, vector<int>& nums2, int i, int j) {
    //     if (i == nums1.size() || j == nums2.size()) return 0;
    //     int res = 0;
    //     // cout << nums1[i] << ", " << nums2[j];
    //     // cout << "\t";
    //     if (memo[i][j] != -1) return memo[i][j];
    //     if (nums1[i] == nums2[j]) {
    //         res = 1 + DP(nums1, nums2, i+1, j+1);
    //     }
    //     else {
    //         res = 0;
    //     }
    //     ans = max(res, ans);
    //     DP(nums1, nums2, i+1, j);
    //     DP(nums1, nums2, i, j+1);
    //     memo[i][j] = res;
    //     return res;
    // }
};

int main() {
    vector<int> nums1 = {
        // 0,1,1,1,1
        1,2,3,2,1
        // 0, 0, 0, 0, 0
        // 1,0,0,0,1
    };
    vector<int> nums2 = {
        // 1,0,1,0,1
        3,2,1,4,7
        // 0, 0, 0, 0, 0
        // 1,0,0,1,1
    };
    Solution so;
    int res = so.findLength(nums1, nums2);
    cout << res;
}