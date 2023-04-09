from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt = 0
        def dfs(i, j):
            grid[i][j] = "0"
            dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            for dir in dirs:
                x = i + dir[0]
                y = j + dir[1]
                if self.isValid(x, y, m, n) and grid[x][y] == "1":
                    dfs(x, y)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    cnt += 1
                    dfs(i, j)
        return cnt

    def isValid(self, x, y, m, n):
        return x>=0 and x<m and y>=0 and y<n

so = Solution()
grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
result = so.numIslands(grid)
print(result)
assert result == 3