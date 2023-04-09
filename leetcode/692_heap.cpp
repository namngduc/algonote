#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pi;

class Compare {
public:
    bool operator()(const pi& a, const pi& b) {
        if (a.first == b.first) return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pi, vector<pi>, Compare> pq;
        unordered_map<string, int> map;
        for (string w : words) map[w]++;
        for (auto x : map) {
            pq.push({x.second, x.first});
        }
        vector<string> res;
        while (!pq.empty() && k > 0) {
            pair<int, string> top = pq.top();
            pq.pop();
            res.push_back(top.second);
            k--;
        }
        return res;
    }
};

int main() {
    vector<string> words = {
        // "the","day","is","sunny","the","the","the","sunny","is","is"
        "i","love","leetcode","i","love","coding"
        // "a","aa","aaa"
    };
    // int k = 4;
    int k = 2;
    // ["the","is","sunny","day"]
    Solution* so = new Solution();
    vector<string> res = so->topKFrequent(words, k);
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
}