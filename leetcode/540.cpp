#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (mid % 2 == 1) {
                mid--;
            } 
            if (nums[mid] != nums[mid+1]) {
                r = mid;
            }
            else {
                l = mid+2;
            }
        } 
        return nums[l];
    }
};

int main() {
    vector<int> nums {
        // 1,1,2,3,3,4,4,8,8
        3,3,7,7,10,11,11
    };
    Solution* so = new Solution();
    int res = so->singleNonDuplicate(nums);
    cout << res << endl;
}