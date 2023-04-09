#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int N = satisfaction.size();
        vector<vector<int>> dp(N+1, vector<int> (N+2, 0));
        for (int i = N-1; i >= 0; i--) {
            for (int time = 1; time <= N; time++) {
                dp[i][time] = max(time * satisfaction[i] + dp[i+1][time+1], dp[i+1][time]);
            }
        }
        return dp[0][1];
    }
};


int main() {
// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.
    vector<int> satisfaction = {
        -1,-8,0,5,-9
    };
    Solution* so = new Solution();
    int res = so->maxSatisfaction(satisfaction);
    cout << res << endl;
}