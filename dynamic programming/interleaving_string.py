from typing import List

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        # if len(s1) + len(s2) != len(s3): return False
        # m,  n = len(s1), len(s2)
        # dp = [[-1 for _ in range(n+1)] for _ in range(m+1)]
        # def dfs(i, j):
        #     ans = False
        #     if i == m and j == n: return True
        #     if dp[i][j] != -1: return dp[i][j]
        #     if i < m and s1[i] == s3[i+j]:
        #         ans |= dfs(i+1, j)
        #     if j < n and s2[j] == s3[j+i]:
        #         ans |= dfs(i, j+1)
        #     dp[i][j] = ans
        #     return ans
        # return dfs(0, 0)
        if len(s1) + len(s2) != len(s3): return False
        m, n = len(s1), len(s2)
        dp = [[False for _ in range(n+1)] for _ in range(m+1)]
        dp[m][n] = True
        for i in range(m, -1, -1):
            for j in range(n, -1, -1):
                if i < m and s1[i] == s3[i+j]:
                    dp[i][j] |= dp[i+1][j]
                if j < n and s2[j] == s3[i+j]:
                    dp[i][j] |= dp[i][j+1]
        return dp[0][0] 

so = Solution()
s1 = "aabee"
s2 = "dbbac"
s3 = "aadbbbacee"
res = so.isInterleave(s1, s2, s3)
print(res)