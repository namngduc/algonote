#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> map;
        for (int i = 0; i < order.size(); i++) {
            map[order[i]] = char(i + 97);
        }
        string prev = "";
        for (string w : words) {
            string map_w = "";
            for (char c : w) {
                map_w += map[c];
            }
            if (prev > map_w) {
                return false;
            }
            prev = map_w;
        }
        return true;
    }
};

int main() {
// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. 
// The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet,
// return true if and only if the given words are sorted lexicographically in this alien language.

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// ["kuvp","q"] "ngxlkthsjuoqcpavbfdermiywz"
// Output: true
    vector<string> words= {
        // "hello","leetcode"
        // "word","world","row"
        "kuvp","q"
    };
    string order = "ngxlkthsjuoqcpavbfdermiywz";
    Solution* so = new Solution();
    bool res = so->isAlienSorted(words, order);
    cout << (res == 0 ? "False" : "True") << endl;
}