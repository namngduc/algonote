#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(366, -1);
        unordered_set<int> daySet;
        for (int day : days) {
            daySet.insert(day);
        }
        return DP(1, daySet, costs, memo);
    }
    
    int DP(int i, unordered_set<int>& daySet, vector<int>& costs, vector<int>& memo) {
        if (i > 365) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int ans = 0;
        if (daySet.count(i)) {
            ans = min({DP(i+1, daySet, costs, memo) + costs[0], DP(i+7, daySet, costs, memo) + costs[1], DP(i+30, daySet, costs, memo) + costs[2]});
        }
        else {
            ans = DP(i+1, daySet, costs, memo);
        }
        memo[i] = ans;
        return ans;
    }
};


int main() {
// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
// On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
// On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
// In total, you spent $11 and covered all the days of your travel.

// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// Output: 17
    vector<int> days = {
        1,4,6,7,8,20
    };
    vector<int> costs = {
        2,7,15
    };
    Solution* so = new Solution();
    int res = so->mincostTickets(days, costs);
    cout << res << endl;
}