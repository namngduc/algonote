#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> check(words.begin(), words.end());
        vector<string> ans;
        for (string w : words) {
            vector<int> memo(w.size(), 0);
            int cnt = 0;
            if (!DP(w, check, 0, cnt, memo)) continue;
            ans.push_back(w);
        }
        return ans;
    }
    bool DP(string word, unordered_set<string>& check, int pos, int cnt, vector<int>& memo) {
        if (pos >= word.size()) {
            if (cnt > 1) {
                return true;
            }
            return false;
        }
        if (memo[pos] == 1) return false;
        string curr = "";
        for (int i = pos; i < word.size(); i++) {
            curr += word[i];
            if (check.find(curr) != check.end() && DP(word, check, i+1, cnt+1, memo) == true) {
                return true;
            }
        }
        memo[pos] = 1;
        return false;
    }
};

int main() {
    // Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
    // Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
    vector<string> words = {
        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
        // "cat","dog","catdog"
    };
    Solution* so = new Solution();
    vector<string> res = so->findAllConcatenatedWordsInADict(words);
    for (string s : res) {
        cout << s << " ";
    }
}