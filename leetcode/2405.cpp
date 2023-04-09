#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> check;
        int cnt = 0;
        for (char c : s) {
            if (!check.count(c)) {
                check.insert(c);
            }
            else {
                check.clear();
                check.insert(c);
                cnt++;
            }
        }
        cnt++;
        return cnt;
    }
};


int main() {
    // Input: s = "abacaba"
    // Output: 4
    string s = "abacaba";
    Solution* so = new Solution();
    int res = so->partitionString(s);
    cout << res << endl;
}