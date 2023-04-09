#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEven = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) sumEven+=nums[i];
        }
        vector<int> res;
        for (vector<int> q : queries) {
            int i = q[1], val = q[0];
            int tmp = nums[i] + val;
            if (nums[i] % 2 == 0 && val % 2 == 0) {
                sumEven += val;
            }
            else if (nums[i] % 2 == 0 && val % 2 != 0) {
                sumEven -= nums[i];
            }
            else if (nums[i] % 2 != 0 && val % 2 != 0) {
                sumEven += tmp;
            }
            else {
                sumEven += 0;
            }
            nums[i] = tmp;
            res.push_back(sumEven);
        }
        return res;
    }
};
// Case 1: nums[i] even and val even. nums += val
// Case 2: nums[i] even and val odd. nums -= nums[i]
// Case 3: nums[i] odd and val odd. nums += nums[i] + val
// Case 4: nums[i] odd and val even. nums = nums

// Explanation: At the beginning, the array is [1,2,3,4].
// After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
// After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
// After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
// After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
int main() {
    vector<int> nums = {
        1,2,3,4
    };
    vector<vector<int>> queries = {
        {1,0},{-3,1},{-4,0},{2,3}
    };
    Solution so;
    vector<int> res = so.sumEvenAfterQueries(nums, queries); 
    for (int x : res) {
        cout << x << " ";
    }
}