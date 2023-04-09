#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res = "";
        int cnt = 1;
        int i = 1;
        for (; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                cnt++;
            }
            else {
                res += std::to_string(cnt);
                res += s[i-1];
                cnt = 1;
            }
        }
        res += std::to_string(cnt);
        res += s[i-1];
        return res;
    }
};

int main() {
    // Input: n = 4
    // Output: "1211"
    // Explanation:
    // countAndSay(1) = "1"
    // countAndSay(2) = say "1" = one 1 = "11"
    // countAndSay(3) = say "11" = two 1's = "21"
    // countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
    // n = 5;
    // say "1211"
    // "111221";
    int n = 5;
    Solution* so = new Solution();
    string res = so->countAndSay(n);
    cout << res << endl;
}