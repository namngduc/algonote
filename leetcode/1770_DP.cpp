#include <bits/stdc++.h>
using namespace std;

class Solution {
map<tuple<int, int, int>, int> memo;
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int N = nums.size() - 1;
        return DP(nums, multipliers, 0, N, 0);

    }
    int DP(vector<int>& nums, vector<int>& multi, int i, int j, int k) {    
        if (k >= multi.size() || i > j) return 0;
        if (memo.find(make_tuple(i, j, k)) != memo.end()) return memo[{i, j, k}];    
        int left = DP(nums, multi, i+1, j, k+1) + nums[i]*multi[k];
        int right = DP(nums, multi, i, j-1, k+1) + nums[j]*multi[k];
        int res = max(left, right);
        memo[make_tuple(i, j, k)] = res;
        return res;

    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<int> multi = {3,2,1};
    Solution so;
    int res = so.maximumScore(nums, multi);
    cout << res;
}