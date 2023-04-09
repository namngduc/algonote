from typing import List

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        self.res = 0
        memo = set()
        self.ans = []
        def dp(track, curr):
            if len(track) == len(words):
                return
            indent = tuple(track)
            if indent in memo: return 
            for k in range(len(words)):
                if k in track: continue
                track.append(k)
                # print(track)
                curr = "".join([words[i] for i in track])
                # curr += words[k]
                if self.isPalindrome(curr):
                    self.ans.append(curr)
                    self.res = max(len(curr), self.res)
                dp(track, curr)
                track.pop()
            memo.add(indent)
        dp(track=[], curr="")
        print(self.ans)
        return self.res
                
    def isPalindrome(self, s):
        l, r = 0, len(s)-1
        while l < r:
            if s[l]!=s[r]:
                return False
            l+=1
            r-=1
        return True

so = Solution()
words = ["dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"]
so.longestPalindrome(words)