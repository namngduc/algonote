#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long res = 0;
        long long prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            res = max(res, (prefixSum + i)/(i+1));
        }
        return res;
    }
};


int main() {
    // Return the minimum possible value of the maximum integer of nums after performing any number of operations.
    // Hints: Perform a binary search over the minimum value that can be achieved for the maximum number of the array.
    // In each binary search iteration, iterate through the array backwards, greedily decreasing the current element until it is within the limit.

    // Input: nums = [3,7,1,6]
    // Output: 5
    // Explanation:
    // One set of optimal operations is as follows:
    // 1. Choose i = 1, and nums becomes [4,6,1,6].
    // 2. Choose i = 3, and nums becomes [4,6,2,5].
    // 3. Choose i = 1, and nums becomes [5,5,2,5].
    // The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
    // Therefore, we return 5.
    vector<int> nums = {
        3,7,1,6
    };
    Solution* so = new Solution();
    int res = so->minimizeArrayValue(nums);
    cout << res << endl;
}