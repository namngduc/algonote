#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
       int MOD = 1e9 + 7;
       int cnt_4 = n/2;
       int cnt_5 = n - n/2;
       long long odd = binPow(4, cnt_4) % MOD;
       long long even = binPow(5, cnt_5) % MOD;
       return (odd * even) % MOD; 
    }
    
    long long binPow(long long a, long long b) {
        if (b == 0) {
            return 1;
        }
        long long res = binPow(a, b/2);
        if (b & 1) {
            return res*res*a;
        }
        else 
            return res*res;
    }
};

int main() {
    // even: 0, 2, 4, 6, 8
    // odd: 2, 3, 5, 7
    // even index is even
    // odd index is prime (2, 3, 5, or 7).
    int n = 50;
    // 400;
    // 564908303
    Solution* so = new Solution();
    int res = so->countGoodNumbers(n);
    cout << res;
}