#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int N = nums.size(), cnt = 0;
        for (int i = N-1; i >= 0; i--) {
            if (nums[i] == 0) {
                cnt += 1;
                nums[i] = cnt;
            } 
            else {
                nums[i] = 0;
                cnt = 0;
            }
        }
        for (int n : nums) res += n;
        return res; 
    }
};


int main() {
    // Input: nums = [1,3,0,0,2,0,0,4]
    // Output: 6
    // Input: nums = [0,0,0,2,0,0]
    // Output: 9
    vector<int> nums = {
        // 1,3,0,0,2,0,0,4
        0,0,0,2,0,0
    };
    Solution* so = new Solution();
    long long res = so->zeroFilledSubarray(nums);
    cout << res << endl;
}