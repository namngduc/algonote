#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        int N = nums.size();
        unordered_map<int, int> map;
        int i = 0;
        while (i < k && i < N) {
            map[nums[i]]++;
            sum += nums[i];
            i++;
        }
        if (map.size() == k) res = sum;
        while (i < N) {
            for (auto &[i, j] : map) {
                cout << i << ", " << j << endl;
            }
            map[nums[i]]++;
            map[nums[i-k]]--;
            sum += nums[i];
            sum -= nums[i-k];
            if (map[nums[i-k]] == 0) map.erase(nums[i-k]);
            if (map.size() == k) res = max(res, sum);
            i++;
        }
        return res;
    }
};

int main() {
    // [4,4,4]
    vector<int> nums = {
        // 1,5,4,2,9,9,9
        // 4,3,3,3,2 
        // 5,5,5,2,3
        1,1,1,1,1,1
        // 1,1,1,7,8,9
    };
    int k = 1;
    Solution* so = new Solution();
    long long res = so->maximumSubarraySum(nums, k);
    cout << res << endl;
}