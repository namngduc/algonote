#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res = {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> map;
        for (int x : changed) {
            map[x]++;
        }
        int N = changed.size();
        if (N < 2) return {};
        for (int i = 0; i < N; i++) {
            int twice = changed[i] * 2;
            if (map[changed[i]] > 0 && map.find(twice) != map.end()) {
                map[changed[i]]--;
                map[twice]--;
                res.push_back(changed[i]);
            }
        }
        for (auto x : map) {
            if (x.second != 0) return {};
            // cout << x.first << ", " << x.second;
            // cout << "\n";
        }
        // for (int x : res) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        return res;
    }
};

int main() {
    vector<int> changed = {
        // 1,3,4,2,6,8
        // 6,3,0,1
        0, 0, 0, 0, 0
    };
    Solution so;
    vector<int> res = so.findOriginalArray(changed);
}