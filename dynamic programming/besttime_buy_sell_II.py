from functools import lru_cache
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @lru_cache(None)
        def dfs(s, buy):
            if s >= len(prices): return 0
            if buy:
                result = max(-prices[s] + dfs(s+1, not buy), dfs(s+1, buy))
            else:
                result = max(prices[s] + dfs(s+1, not buy), dfs(s+1, buy))
            return result
        return dfs(0, True)

so = Solution()
prices = [7, 1, 5, 3, 6, 4]
print(so.maxProfit(prices))