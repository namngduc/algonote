#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int nonCircular = kadane(nums);
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            nums[i] = -nums[i];
        }
        int circular = totalSum + kadane(nums);
        if (circular == 0) return nonCircular;
        return max(nonCircular, circular);
    }
    int kadane(vector<int>& nums) {
        int maxSum = nums[0], currentSum = nums[0];
        int N = nums.size();
        for (int i = 1; i < N; i++) {
            if (currentSum < 0) {
                currentSum = 0;
            }
            currentSum += nums[i];
            maxSum = max(currentSum, maxSum);

        }
        return maxSum;
    }
};

int main() {
    // Input: nums = [1,-2,3,-2]
    // Output: 3
    // Input: nums = [5,-3,5]
    // Output: 10
    vector<int> nums = {
        // 1, -2, 3, -2
        5, -3, 5
    };
    Solution* so = new Solution();
    int res = so->maxSubarraySumCircular(nums);
    cout << res << endl;
}