#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        else 
            return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), compare);
        for (auto v : properties) {
            cout << "(" << v[0] << ", " << v[1] << ")" << "\t";
        }
        int N = properties.size();
        int res = 0;
        int tmp = INT_MIN;
        for (int i = N-1; i >= 0; i--) {
            if (properties[i][1] < tmp) {
                res++;
            }
            tmp = max(tmp, properties[i][1]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> properties = {
        // {1,5},{10,4},{4,3}
        // {1,5},{10,6},{4,5},{4,5},{10,7}
        // {1,1},{2,1},{2,2},{1,2}
        {7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}
        };
    Solution solution;
    int res = solution.numberOfWeakCharacters(properties);
    cout << res;
} 
