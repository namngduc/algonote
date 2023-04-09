#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string s) {
        int N = s.size();
        int l = -1, r = -1;
        for (int i = 0; i <= N; i++) {
            if (i == N || s[i] == 'R') {
                if (r > l) {
                    while (r < i) {
                        r++;
                        s[r] = 'R'; 
                    }
                }
                r = i;
            }
            else if (s[i] == 'L') {
                if (l > r || r == -1) {
                    while (l < i) {
                        l++;
                        s[l] = 'L';
                    }
                    l = i;
                }
                else if (l < r) {
                    l = i;
                    int lo = r+1;
                    int hi = l-1;
                    while (lo < hi) {
                        s[lo++] = 'R';
                        s[hi--] = 'L';
                    }
                }
            }
        }
        return s;
    }
};

int main() {
    // Case 1: Meet 'R' and r > l: R...R -> Fill right.
    // Case 2: Meet 'R' and r < l: L...R -> Do nothing.
    // Case 3: Meet 'L' and l > r: L...L -> Fill left.
    // Case 4: Meet 'L' and l < r: R...L -> Fill balance. 

    // There are n dominoes in a line, and we place each domino vertically upright. 
    // In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
    // After each second, each domino that is falling to the left pushes the adjacent domino on the left. 
    // Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
    // When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
    // For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
    
    string dominoes = ".L.R.L.LR..L..";
    // string dominoes = "..R..";
    // Expected "..RRR"
    Solution so;
    string res = so.pushDominoes(dominoes);
    cout << res;
    // assert (res == "LL.RR.LLRRLL..");
}