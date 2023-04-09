#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        // cout << isPalindrome("abcdba");
        return res;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true; 
    }
};

int main() {
    // [[0,1],[1,0],[3,2],[2,4]]
    vector<string> words = {
        "abcd","dcba","lls","s","sssll"
    };
    Solution so;
    vector<vector<int>> res = so.palindromePairs(words);
}