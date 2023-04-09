from typing import List

class Solution:
    def numTrees(self, n: int) -> int:
        dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        def trees(lo, hi):
            if lo >= hi: return 1
            if dp[lo][hi] != -1: return dp[lo][hi]
            total = 0
            for i in range(lo, hi+1):
                total += trees(lo, i-1)*trees(i+1, hi)
            dp[lo][hi] = total
            return total
        return trees(1, n)
        

so = Solution()
nums = 3
print(so.numTrees(nums))