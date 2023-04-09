#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int N = s.length();
        int i = 0, j = 0;
        while (i <= N) {
            if (s[i] == ' ' || i == N) {
                int k = i-1;
                while (j <= k) {
                    char tmp = s[j];
                    s[j] = s[k];
                    s[k] = tmp;
                    j++;
                    k--;
                }
                j = i+1;
            }
            i++;
        }
        return s;
    }
};

int main() {
    string s = "Let's take LeetCode contest";
    string ans = "s'teL ekat edoCteeL tsetnoc";
    Solution so;
    string res = so.reverseWords(s);
    assert(res == ans);
    cout << res;
}