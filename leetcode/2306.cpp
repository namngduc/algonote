#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        vector<unordered_set<string>> arr(26);
        for (string id : ideas) {
            arr[id[0] - 'a'].insert(id.substr(1));
        }
        for (int i = 0; i < 25; i++) {
            for (int j = i+1; j < 26; j++) {
                unordered_set<string> set;
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                res += (arr[i].size() - set.size()) * (arr[j].size() - set.size()) * 2;
            }
        }
        return res;
    }
};

int main() {
    // Input: ideas = ["coffee","donuts","time","toffee"]
    // Output: 6
    vector<string> ideas = {
        "coffee","donuts","time","toffee"
    };
    Solution* so = new Solution();
    long long res = so->distinctNames(ideas);
    cout << res << endl;
}