#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> limits;
        for (char c : s) {
            limits[c]++;
        }
        for (char c : {'a', 'b', 'c'}) {
            limits[c]-=k;
            if (limits[c] < 0) {
                return -1;
            }
        }
        unordered_map<char, int> cnt = {{'a', 0}, {'b', 0}, {'c', 0}};
        int res = 0, left = 0;
        for (int right = 0; right < s.size(); right++) {
            cnt[s[right]]++;
            while (cnt[s[right]] > limits[s[right]]) {
                cnt[s[left]]--;
                left++;
            }
            res = max(res, right - left+1);
        }
        return s.size() - res;
    }
};

int main() {
    // Input: s = "aabaaaacaabc", k = 2
    // Output: 8
    // 1. Start by counting the frequency of each character and checking if it is possible.
    // 2. If you take x characters from the left side, what is the minimum number of characters you need to take from the right side? 
    // Find this for all values of x in the range 0 ≤ x ≤ s.length.
    // 3. Use a two-pointers approach to avoid computing the same information multiple times.
    string s = "aabaaaacaabc";
    int k = 2;
    Solution* so = new Solution();
    int res = so->takeCharacters(s, k);
    cout << res << endl;
}
