#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        for (string w : words) {
            map[w]++;
        }
        int res = 0;
        int center = 0;
        int size = 2;
        for (auto x : map) {
            string w = x.first;
            string rever = string(1, w[1]) + w[0];
            if (w == rever) {
                res += 2 * (x.second/2);
                if (x.second % 2 == 1) center = 1;
            }
            if (map.find(rever) != map.end() && w != rever) {
                int min_size = min(map[w], map[rever]);
                res += min_size;
            }
        }
        return res * size + (center ? size : 0);     
    }
};

int main() {
    vector<vector<string>> words = {
        {"lc","cl","gg", "aa", "bb"},
        {"ab","ty","yt","lc","cl","ab"},
        {"cc","ll","xx"},
        {"dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"},
        {"mm","mm","yb","by","bb","bm","ym","mb","yb","by","mb","mb","bb","yb","by","bb","yb","my","mb","ym"},
        {"ll","lb","bb","bx","xx","lx","xx","lx","ll","xb","bx","lb","bb","lb","bl","bb","bx","xl","lb","xx"},
        {"nn","nn","hg","gn","nn","hh","gh","nn","nh","nh"},
        {"qw","rr","ll","vv","iw","wq","cc","wi","jj","iw","pp","iw","mm","ss","bb","oo","wi","dd","wq","ff","qi","qw","qi","qi","zz","wq","iw","wi","qq","qw","wi","hh","qi","pp","vv","wi","wq","wi","wi","wi","iw","qi","bb","qw","qi","rr"},
        {"ga","ac","aa","ag","gc","cg","aa","ac","cg","ga","ga","gg","cg","ca","cg","gg","ca","ag","cc","ag","aa","cg","gg"}
    };
    // 6
    // 8
    // 2
    // 22
    // 30
    // 26
    // 14
    // 54
    // 34
    Solution* so = new Solution();
    for (auto w : words) {
        int res = so->longestPalindrome(w);
        cout << res << endl;
    }
}