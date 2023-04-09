#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        cout << "Size: " << nums.size() - 1 << endl;
        int res = 1;
        while (r < nums.size()-1) {
            while (r < nums.size()-1 && nums[r] == nums[r+1]) {
                r++;
            }
            cout << l << ", " << r << endl;
            if (r == nums.size() - 1) break;
            l++;
            r++;
            nums[l] = nums[r];
            res++;
        }
        cout << "Res: " << res << endl;
        return nums;
    }
};

int main() {
    vector<int> nums = {
        0,0,1,1,1,2,2,3,3,4
        // 1, 1
    };
    Solution* so = new Solution();
    vector<int> res = so->removeDuplicates(nums);
    for (int n : res) cout << n << " ";
    cout << endl;
    // cout << nums[5] << endl;
}