from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        return self.dfs(0, 0, m, n, obstacleGrid, dp)
         
    def dfs(self, i, j, m, n, grid, dp):
        if (i==m or j==n or grid[i][j]==1): return 0
        if dp[i][j] != -1: return dp[i][j]
        if (i==m-1 and j==n-1):
            if grid[i][j]==1: return 0
            return 1
        dp[i][j] = self.dfs(i+1,j, m, n, grid, dp) + self.dfs(i, j+1, m, n, grid, dp)
        return dp[i][j]


so = Solution()
# obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
obstacleGrid = [[0,0]]
print(so.uniquePathsWithObstacles(obstacleGrid))