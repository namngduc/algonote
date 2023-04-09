#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> win, lose;
        for (vector<int> v : matches) {
            win[v[0]]++;
            lose[v[1]]++;
        }
        vector<vector<int>> res;
        vector<int> ans1, ans2;
        for (auto& [k, v] : win) {
            if (!lose.count(k)) {
                ans1.push_back(k);
            }
        }
        for (auto& [k, v] : lose) {
            if (v==1) {
                ans2.push_back(k);
            }
        }
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        res.push_back(ans1);
        res.push_back(ans2);
        return res;
    }
};

int main() {
    // Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    // Output: [[1,2,10],[4,5,7,8]]    
    vector<vector<int>> matches = {
        {1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}
    };
    Solution* so = new Solution();
    vector<vector<int>> res = so->findWinners(matches);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " \n"[j==res[i].size()-1];
        }
    }
}