#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> queue;
        unordered_set<string> set(bank.begin(), bank.end());
        unordered_set<string> seen;
        seen.insert(start);
        int N = start.length();
        queue.push({start, 0});
        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();
            if (top.first == end) {
                return top.second;
            }
            for (int i = N-1; i>=0; i--) {
                char tmp = top.first[i];
                for (char c : {'A', 'C', 'G', 'T'}) {
                    top.first[i] = c;
                    if (seen.find(top.first) != seen.end()) continue;
                    if (set.find(top.first) != set.end()) {
                        seen.insert(top.first);
                        queue.push({top.first, top.second+1});
                    }
                }
                top.first[i] = tmp;
           }
        }
        return -1;
    }
};

int main() {
    // 'A', 'C', 'G', and 'T'
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    // 2
    Solution* so = new Solution();
    int res = so->minMutation(start, end, bank);
    cout << res << endl;
}