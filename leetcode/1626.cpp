#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int N =  scores.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < N; i++) {
            arr.push_back(make_pair(ages[i], scores[i]));
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        vector<int> dp(N, arr[0].second);
        for (int i = 0; i < N; i++) {
            dp[i] = arr[i].second;
            for (int j = 0; j < i; j++) {
                if (arr[j].second <= arr[i].second) {
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

int main() {
// Input: scores = [4,5,6,5], ages = [2,1,2,1]
// Output: 16
    vector<int> scores = {
        // 4, 5, 6, 5
        1
    };
    vector<int> ages = {
        // 2, 1, 2, 1
        4
    };
    Solution* so = new Solution();
    int res = so->bestTeamScore(scores, ages);
    cout << res << endl;
}