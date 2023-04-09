#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) { 
        long long ans = 0;
        int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            int len = calNumBit(i);
            ans = ((ans << len) % MOD) + i;
        }
        return ans;

    }
    
    int calNumBit(int n) {
        int i = 0;
        while (n > 0) {
            n /= 2;
            i++;
        }
        return i;
    }
};

int main() {
    int n = 12;
    Solution so;
    int res = so.concatenatedBinary(n);
    cout << res;
}