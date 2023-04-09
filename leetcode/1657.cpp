#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<char, int>& a,
            pair<char, int>& b) {
                return a.second < b.second;
            }
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char, int> map_1, map_2;
        vector<pair<char, int>> A, B;
        for (char c : word1) {
            map_1[c]++;
        }
        for (auto& it : map_1) {
            A.push_back(it);
        }
        for (char c : word2) {
            if (map_1.find(c) == map_1.end()) return false;
            map_2[c]++;
        }
        for (auto& it : map_2) {
            B.push_back(it);
        }
        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end(), cmp);
        for (int i = 0; i < A.size(); i++) {
            if (A[i].second != B[i].second) return false;
        }
        return true;
    }
};

int main() {
    // word1 = "abc", word2 = "bca" --> true
    // word1 = "cabbba", word2 = "abbccc" -->true
    // word1 = "uau", word2 = "ssx" --> false
    string word1 = "uau";
    string word2 = "ssx";
    Solution* so = new Solution();
    bool res = so->closeStrings(word1, word2);
    cout << (res == 1 ? "True" : "False") << endl;
}