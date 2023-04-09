#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int N = nums.size();
        int res = 0;
        for (int i = 0; i < N - 2; i++) {
            if (nums[i] < nums[i+1] + nums[i+2]) {
                res = nums[i] + nums[i+1] + nums[i+2];
                break;
            }
        }
        return res;      
    }
};

int main() {
    // Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
    // If it is impossible to form any triangle of a non-zero area, return 0.
    vector<int> nums = {1, 2, 1};
    // {1, 2, 1}
    Solution* so = new Solution();
    int res = so->largestPerimeter(nums);
    cout << res << endl;
}