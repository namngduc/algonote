#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        int N = points.size();
        for (auto& p : points) {
            if (p[0] > minEnd) {
                res++;
                minEnd = p[1];
            }
            else {
                minEnd = min(minEnd, p[1]);
            }
        }
        return res;
    }
};

int main() {
    // Input: points = [[10,16],[2,8],[1,6],[7,12]]
    // Output: 2
    // Input: points = [[1,2],[3,4],[5,6],[7,8]]
    // Output: 4
    // Input: points = [[1,2],[2,3],[3,4],[4,5]]
    // Output: 2
    vector<vector<int>> points = {
        {10,16},{2,8},{1,6},{7,12}
        // {1,2},{3,4},{5,6},{7,8}
    };
    Solution* so = new Solution();
    int res = so->findMinArrowShots(points);
    cout << res << endl;
}