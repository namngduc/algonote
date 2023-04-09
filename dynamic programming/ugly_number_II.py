from typing import List

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n <= 0: return 0
        dp = [0]*(n)
        i_2, i_3, i_5 = 0, 0, 0
        dp[0] = 1
        for i in range(1, n):
            dp[i] = min(dp[i_2]*2, dp[i_3]*3, dp[i_5]*5)
            if dp[i] == 2*dp[i_2]: i_2+=1
            if dp[i] == 3*dp[i_3]: i_3+=1
            if dp[i] == 5*dp[i_5]: i_5+=1
        return dp[n-1]

so = Solution()
n = 11
result = so.nthUglyNumber(n)
print(result)
assert result == 12 
