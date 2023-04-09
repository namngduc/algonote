#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isScramble(string s1, string s2) {
        int N = s1.length();
        vector memo(N, vector(N, vector<int> (N+1, -1)));
        return DP(s1, s2, 0, 0, N, memo);
    }

    int DP(string& s1, string& s2, int i, int j, int len, vector<vector<vector<int>>>& memo) {
        if (memo[i][j][len] != -1) {
            return memo[i][j][len];
        }
        if (len == 1) {
            return (s1[i] == s2[j]) ? 1 : 0;
        }
        for (int k = 1; k < len; k++) {
            if (DP(s1, s2, i, j, k, memo) && DP(s1, s2, i+k, j+k, len-k, memo)) {
                return memo[i][j][len] = 1; 
            }
            else if (DP(s1, s2, i, j+len-k, k, memo) && DP(s1, s2, i+k, j, len-k, memo)) {
                return memo[i][j][len] = 1; 
            }
        }
        return memo[i][j][len] = 0;
    }
};

// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         int N = s1.length();
//         vector dp(N+1, vector(N, vector<int> (N, 0)));
//         for (int i = 0; i < N; i++) {
//             for (int j = 0; j < N; j++) {
//                 dp[1][i][j] = s1[i] == s2[j];
//             }
//         }
//         for (int leng = 2; leng <= N; leng++) {
//             for (int i = 0; i < N+1-leng; i++) {
//                 for (int j = 0; j < N+1-leng; j++) {
//                     for (int newLen = 1; newLen < leng; newLen++) {
//                         if (dp[newLen][i][j] && dp[leng-newLen][i+newLen][j+newLen] || dp[newLen][i][j+leng-newLen] && dp[leng-newLen][i+newLen][j]) {
//                             dp[leng][i][j] = true;
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[N][0][0]; 
//     }
// };


int main() {
// Input: s1 = "great", s2 = "rgeat"
// Output: true
// Explanation: One possible scenario applied on s1 is:
// "great" --> "gr/eat" // divide at random index.
// "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
// "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
// "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
// "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
// "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
// The algorithm stops now, and the result string is "rgeat" which is s2.
// As one possible scenario led s1 to be scrambled to s2, we return true.

// Input: s1 = "abcde", s2 = "caebd"
// Output: false
    string s1 = "abcde";
    string s2 = "caebd";
    Solution* so = new Solution();
    bool res = so->isScramble(s1, s2);
    cout << (res == 1 ? "True" : "False") << endl;

}