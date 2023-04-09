#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int N = s.length();
        string res = "";
        string tmp = s;
        char prev = 'z';
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] < prev) {
                prev = s[i];
            }
            tmp[i] = prev;
        }
        stack<char> stack;
        for (int i = 0; i < N; i++) {
            while(stack.size() && stack.top() <= tmp[i]) {
                res += stack.top();
                stack.pop();
            }
            stack.push(s[i]);
        }
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
            // cout << stack.top() << " ";
            // stack.pop();
            // if (stack.top() >= res.back()) {
            //     tmp += stack.top();
            // }
        }
        // cout << endl;
        cout << "Res: " << res << endl;
        cout << "s: " << s << endl;
        cout << "Tmp: " << tmp << endl;
        return res;
    }
};

int main() {
    string s = "vzhofnpo";
    // "addb"
    // "bydizfve"
    // "vzhofnpo"
    // vzp
    // fnoho
    // Expected: "fnohopzv"
    Solution* so = new Solution();
    string res = so->robotWithString(s);
    cout << res << endl;
}