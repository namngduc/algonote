from typing import List
from functools import lru_cache

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        # dp = [[-1 for _ in range(n)] for _ in range(m)]
        @lru_cache(None)
        def dfs(i, j, m, n):
            minCol, minRow = float("inf"), float("inf")
            if i == m-1 and j == n-1: return grid[i][j]
            if i < m-1: minCol = dfs(i+1, j, m, n)
            if j < n-1: minRow = dfs(i, j+1, m, n)
            return min(minCol, minRow) + grid[i][j]
        return dfs(0, 0, m, n)
    
so = Solution()
grid = [[1,3,1],[1,5,1],[4,2,1]]
print(so.minPathSum(grid))