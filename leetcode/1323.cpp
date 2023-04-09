#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximum69Number (int num) {
        int res = 0;
        int base = 10;
        while (num > base) {
            base *= 10;
        }
        // cout << base << endl;
        base /= 10;
        while (num > 0) {
            int tmp = num/base;
            int re = num%base;
            if (tmp % 6 == 0) {
                res += 9 * base + re;
                break;
            }
            num -= tmp*base;
            res += tmp*base;
            base /= 10;

        }
        return res;
    }
};

int main() {
    // int num = 9669;
    int num = 9999;
    // 9999
    Solution* so = new Solution();
    int res = so->maximum69Number(num);
    cout << res << endl;
}