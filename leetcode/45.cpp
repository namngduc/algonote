#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        int res = DP(nums, 0, memo);
        return res;
    }
    int DP(vector<int>& nums, int i, vector<int>& memo) {
        if (i >= nums.size()-1) {
            return 0;
        }
        if (memo[i] != -1) return memo[i];
        int res = INT_MAX-10;
        for (int j = 1; j <= nums[i]; j++) {
            res = min(res, 1 + DP(nums, i+j, memo));
        }
        memo[i] = res;
        return res;
    }
};

int main() {
// Input: nums = [2,3,1,1,4]
// Output: 2
    vector<int> nums = {
        // 2, 3, 1, 1, 4
        // 2, 3, 0, 1, 4
        5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
    };
    Solution* so = new Solution();
    int res = so->jump(nums);
    cout << res << endl;
}