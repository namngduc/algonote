#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        int i = s.length()-1;
        while (i >= 0) {
            // cout << i << endl;
            // cout << s[i] << endl;
            while (!stack.empty() && i >= 0 && stack.top() == s[i]) {
                stack.pop();
                i--;
            }
            if (i >= 0) {
                stack.push(s[i]);
                i--;
            }
        }
        string res = "";
        while (stack.size() > 0) {
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};

int main() {
    string s = "abbaca";
    // string s = "azxxzy";
    // string s = "aaaaaaaa";
    Solution* so = new Solution();
    string res = so->removeDuplicates(s);
    cout << res << endl;
}