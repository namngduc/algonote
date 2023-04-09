#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        int N = nums2.size();
        int num1_xor = nums1[0];
        for (int i = 1; i < M; i++) {
            num1_xor ^= nums1[i];
        }
        int num2_xor = nums2[0];
        for (int i = 1; i < N; i++) {
            num2_xor ^= nums2[i];
        }
        if (M % 2 == 0) {
            num2_xor ^= num2_xor;
        }
        if (N % 2 == 1) {
            num2_xor ^= num1_xor;
        }
        return num2_xor;
    }
};

int main() {
    vector<int> nums1 = {
        2,1,3
        // 1, 2
        // 2,1,3,5,6
        // 2,1,4,3,5,8,12,13
    };
    vector<int> nums2 = {
        10,2,5,0
        // 3, 4
        // 10,2,5,0,6,9
        // 10,2,5,0,2,13,2,9,7
    };
    // 13
    // 2
    // 8
    Solution* so = new Solution();
    int res = so->xorAllNums(nums1, nums2);
    cout << res;
}