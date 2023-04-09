#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.length();
        if (N == 1) return "";
        bool flag = false;
        for (int i = 0; i < N/2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                flag = true;
                break;
            }
        }

        if (!flag) palindrome[N-1] = 'b';
        return palindrome;
    }
};

int main() {
    string palindrome = "aba";
    // "abccba"
    // aaccba
    Solution* so = new Solution();
    string res = so->breakPalindrome(palindrome);
    cout << res << endl;
}