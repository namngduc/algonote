#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map={{0, -1}};
        int mod = 0;
        for (int i = 0; i < nums.size(); i++) {
            mod += nums[i];
            mod %= k;
            if (map.count(mod)) {
                if (i - map[mod] > 1) return true;
            }
            else
                map[mod] = i;
        }
        return false; 
    }
};
// [23,2,4,6,6]
// 7
// {2, 0} {4, 1} {1, 2} {0, 3}
int main() {
    vector<int> nums = {
        23,2,4,6,7
        // 23,2,6,4,7
    };
    int k = 6;
    Solution* so = new Solution();
    bool res = so->checkSubarraySum(nums, k);
    cout << (res==1 ? "true" : "false") << endl;
}