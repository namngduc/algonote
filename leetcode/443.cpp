#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        if (N == 1) {
            return 1;
        }
        int i = 0, j = 0;
        while (i < N) {
            int cnt = 1;
            while (i < N-1 && chars[i]==chars[i+1]) {
                cnt++;
                i++;
            }
            chars[j] = chars[i];
            j++; i++;
            if (cnt > 1) {
                string s = to_string(cnt);
                for (char c : s) {
                    chars[j] = c;
                    j++;
                }
            }
        }
        for (char c : chars) cout << c << " ";
        cout << "\n";
        return j;
    }
};


// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].


int main() {
    vector<char> chars = {
        'a','a','b','b','c','c','c'
        // 'a','b','b','b','b','b','b','b','b','b','b','b','b'
        // 'a'
    };
    Solution* so = new Solution();
    int res = so->compress(chars);
    cout << res << endl;
}