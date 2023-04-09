#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, N = intervals.size();
        while (i < N && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < N && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval); 
        while (i < N) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};


int main() {
    // Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    // Output: [[1,5],[6,9]]
    // Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    // Output: [[1,2],[3,10],[12,16]]
    vector<vector<int>> intervals = {
        {1,2},{3,5},{6,7},{8,10},{12,16}
    };
    vector<int> newInterval = {
        4, 8
    };
    Solution* so = new Solution();
    vector<vector<int>> res = so->insert(intervals, newInterval);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " \n"[j==res[i].size()-1];
        }
    }
}