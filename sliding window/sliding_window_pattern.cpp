// The Pattern of sliding window algorithm
// int left = 0, right = 0;
// while (right < s.size()) {
//     window.add(s[right]);
//     right++;
//     while (valid) {
//         window.remove(s[left]);
//         left++;
//     }



#include <bits/stdc++.h>

std::string slidingWindow(std::string s, std::string t) {
    int start = 0, minLen=INT_MAX;
    // Two pointers
    int left=0, right=0;
    // Initialize map
    std::unordered_map<char, int> needs;
    std::unordered_map<char, int> window;
    // The number of characters that meet the requirement
    int match = 0;

    for (auto c:t) needs[c]++;

    while (right < s.length()){
        char c1=s[right];
        if (needs.count(c1)) {
            window[c1]++;  // Add to window
            if (window[c1]==needs[c1])
            // The number of occurrences of the character c1 meet the requirement
                match++;
        }
        right++;
        
        // when we found a valid window
        while (match==needs.size()) {
            // Update res if we found the minimum
            if (right - left < minLen) {
                start = left;
                minLen = right-left;
            }
            // Increase left pointer to make it invalid/valid again
            char c2=s[left];
            if (needs.count(c2)) {
                window[c2]--;  // Remove from window
                if (window[c2] < needs[c2])
                    // The number of occurrences of the character c2 no longer meets the requirement 
                    match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
// Time Complexity: O(|S| + |T|). The worse case all characters in T contained in S
// Space Complexity: O(max(S,T))

int main() {
    std::string s="ADOBECODEBANC", t="ABC";
    std::string res=slidingWindow(s, t);
    std::cout << res << "\n";
    return 0;
}
