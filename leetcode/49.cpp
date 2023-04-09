#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string s : strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            map[s].push_back(tmp);
        }
        vector<vector<string>> res;
        // for (auto x : map) {
        //     cout << x.first << ": ";
        //     for (string s : x.second) {
        //         cout << s << " ";
        //     }
        //     cout << endl;
        // }
        cout << "Debug: " << string(2, 2 + 'a') << endl;
        for (auto x : map) res.push_back(x.second);
        return res;
    }
};

int main() {
    vector<string> strs = {
        "eat","tea","tan","ate","nat","bat"
    };
    Solution* so = new Solution();
    vector<vector<string>> res = so->groupAnagrams(strs);
    for (auto v : res) {
        for (string s : v) {
            cout << s << ", ";
        }
        cout << "\n";
    } 
}