#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        // for (int n : arr) cout << n << " ";
        int N = arr.size();
        vector<int> res(N+1, 0);
        stack<int> stack;
        stack.push(0);
        for (int i = 0; i < N; i++) {
            while (arr[stack.top()] > arr[i]) {
                stack.pop();
            }
            int j = stack.top();
            res[i] = res[j] + arr[i]*(i-j);
            stack.push(i);
        }
        long long ans = 0;
        for (int r : res) ans += r % MOD;
        return ans;
    }
};

int main() {
    vector<int> arr = {
        // 3,1,2,4
        11,81,94,43,3
    };
    // 17
    // 444
    Solution* so = new Solution();
    int res = so->sumSubarrayMins(arr);
    cout << res << endl;
}