from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        dp = [[False]*len(s) for _ in range(len(s))]
        res, curr = [], []
        def backtrack(res, curr, s, start):
            if start >= len(s): 
                res.append(curr.copy())
                return
            for end in range(start, len(s)):
                # if (s[start]==s[end] and (end - start <= 2 or not dp[start+1][end-1])):
                # if self.isPalindrome(s, start, end):
                substring = s[start:end+1]
                if substring == substring[::-1]:
                    # dp[start][end] = True
                    curr.append(substring)
                    backtrack(res, curr, s, end+1)
                    curr.pop()
        backtrack(res, curr, s, 0)
        print(res)
        return res

    def isPalindrome(self, s, start, end):
        while (start <= end):
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True        

so = Solution()
s = "aab"
res = so.partition(s)
output = [["a","a","b"],["aa","b"]]
assert res == output