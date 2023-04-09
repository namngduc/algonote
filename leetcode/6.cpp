#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        vector<string> arr(numRows, "");
        int j = 0, direct = -1;
        for (int i = 0; i < s.size(); i++) {
            if (j == 0 | j == numRows-1) {
                direct *= -1;
            }
            arr[j] += s[i];
            if (direct == 1) j++;
            else {
                j--;
            }
        }
        string res = "";
        for (auto& it : arr) {
            res += it;
        }
        return res;
    }
};

int main() {
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
    string s = {
        "PAYPALISHIRING"
    };
    int numRows = 4;
    Solution* so = new Solution();
    string res = so->convert(s, numRows);
    cout << res << endl;
}