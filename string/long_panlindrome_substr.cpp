#include<bits/stdc++.h>

class Solution {
public:
    std::string panlindrome(std::string& s, int l, int r) {
        while (l>=0 && r < s.size() && s[l] == s[r]) {
            l--;r++; 
        }
        return s.substr(l+1, r-l-1);
    }

    std::string longestPanlindrome(std::string& s) {
        std::string res;
        for (int i=0; i< s.size(); ++i) {
            std::string s1 = panlindrome(s, i, i);
            std::string s2 = panlindrome(s, i, i+1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
};

int main() {
    std::string s="babad";
    Solution so;
    std::string result = so.longestPanlindrome(s);
    std::cout << result << std::endl;
    return 0;
}