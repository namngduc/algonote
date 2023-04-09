#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;
        string res = "";
        int i = s.length() - 1;
        while (i >= 0) {
            if (!stack.empty()) {
                char top = stack.top();
                if ((isupper(top) && tolower(top) == s[i]) || (islower(top) && toupper(top) == s[i])) {
                    stack.pop();
                    i--;
                }
                else {
                    stack.push(s[i]);
                    i--;
                }
            }
            else {
                stack.push(s[i]);
                i--;
            }
        }
        while (!stack.empty()) {
            // cout << stack.top() << endl;
            // stack.pop();
            res += stack.top();
            stack.pop();
        }
        return res;  
    }
};

int main() {
    // "abBAcC"
    // ""
    string s = "abBAcC";
    // string s = "leEeetcode";
    // string s = "s";
    // "leetcode"
    // 
    Solution* so = new Solution();
    string res = so->makeGood(s);
    cout << res << endl;
}