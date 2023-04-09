#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i < m; i++) {
            if (haystack[i] == needle[0]) {
                int k = i;
                int j = 0;
                cout << "k: " << k << endl;
                while (k < m && j < n) {
                    if (haystack[k] == needle[j]) {
                        k++;
                        j++;
                    }
                    else break;
                }
                cout << "k: " << k << "  " << "j: " << j << endl;
                cout << "i: " << i << endl;
                if (j == n) return i;
            }
        }
        return -1;
    }
};

int main() {
    // Input: haystack = "sadbutsad", needle = "sad"
    // Output: 0
    // Input: haystack = "leetcode", needle = "leeto"
    // Output: -1
    string haystack = "sadbuttsad";
    string needle = "batt";
    Solution* so = new Solution();
    int res = so->strStr(haystack, needle);
    cout << res << endl;
}