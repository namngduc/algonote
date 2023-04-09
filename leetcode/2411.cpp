#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 0);
        vector<vector<int>> bin;
        for (int n : nums) {
            vector<int> int2bin = convertBinary(n);
            bin.push_back(int2bin);
        }
        for (int i = 0; i < bin.size(); i++) {
            for (int j = 0; j < 31; j++) {
                cout << bin[i][j] << " ";
            }
            cout << "\n";
        }
        vector<int> cnt(31, 0);
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < 31; j++) {
                if (bin[i][j] == 1) {
                    cnt[j] = i;
                }
            }
            int mx = *max_element(cnt.begin(), cnt.end());
            cout << mx << ", " << i << "\n";
            int tmp = max(mx, i) - i + 1;
            res[i] = tmp;
        }
        return res;
    }
    vector<int> convertBinary(int n) {
        vector<int> arr(31, 0);
        int i = 30;
        while (n > 0) {
            int x = n % 2;
            arr[i] = x;
            n /= 2;
            i--;
        }
        return arr;

    }
};

// Explanation:
// The maximum possible bitwise OR starting at any index is 3. 
// - Starting at index 0, the shortest subarray that yields it is [1,0,2].
// - Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
// - Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
// - Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
// - Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].

int main() {
    vector<int> nums = {
        // 1,0,2,1,3
        1, 0
    };
    vector<int> ans = {
        // 3,3,2,2,1
        1, 1
    };
    Solution so;
    vector<int> res = so.smallestSubarrays(nums);
    // assert(res == ans);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}