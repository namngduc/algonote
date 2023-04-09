from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        self.res = []
        track = []
        self.backtrack(s, 0, track)
        return self.res

    def backtrack(self, s, k, track):
        if k==len(s):
            self.res.append(track.copy())
            return
        curr = ""
        for i in range(k, len(s)):
            curr += s[i]
            if self.isPalindrome(curr):
                track.append(curr)
                self.backtrack(s, i+1, track)
                track.pop()

    def isPalindrome(self, string):
        l, r = 0, len(string) - 1
        while l < r:
            if string[l] != string[r]:
                return False
            l+=1
            r-=1
        return True

so = Solution()
s = "aabaa"
result = so.partition(s)
assert result == [["a","a","b","a","a"],["a","a","b","aa"],["a","aba","a"],["aa","b","a","a"],["aa","b","aa"],["aabaa"]]
print(result)