#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j-1][i] > strs[j][i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    // Input: strs = ["cba","daf","ghi"]
    // Output: 1
    // Input: strs = ["zyx","wvu","tsr"]
    // Output: 3
    vector<string> strs = {
        // "cba","daf","ghi"
        "zyx","wvu","tsr"
    };
    Solution* so = new Solution();
    int res = so->minDeletionSize(strs);
    cout << res << endl;
}