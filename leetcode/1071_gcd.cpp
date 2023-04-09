#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int gcd = getGcd(str1.size(), str2.size());
        return str1.substr(0, gcd);
    }
    int getGcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getGcd(b, a%b);
    }
};

int main() {
    // LEET
    // LEET
    string str1 = {
        // "ABCABC"
        "LEET"
    };
    string str2 = {
        "LEET"
        // "ABC"
    };
    Solution* so = new Solution();
    string res = so->gcdOfStrings(str1, str2);
    cout << res << endl;
}