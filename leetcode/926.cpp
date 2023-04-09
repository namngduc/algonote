#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> forward(s.size() + 1), backward(s.size() + 1);
        for (int i = 1; i <= s.size(); i++) {
            forward[i] += forward[i-1] + (s[i-1] == '1' ? 1 : 0);
        }
        for (int j = s.size() - 1; j >= 0; j--) {
            backward[j] += backward[j+1] + (s[j] == '0' ? 1 : 0); 
        }
        int res = INT_MAX;
        for (int i = 0; i <= s.size(); i++) res = min(res, forward[i] + backward[i]);
        return res;
    }
};

int main() {
    string s = "010110";
    Solution* so = new Solution();
    int res = so->minFlipsMonoIncr(s);
    cout << res << endl;
}