from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        self.res = 0
        self.cnt = 0
        def dfs(i, j):
            self.cnt += 1
            grid[i][j] = 0
            dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            for dir in dirs:
                x = i + dir[0]
                y = j + dir[1]
                if self.isValid(x, y, m, n) and grid[x][y] == 1:
                    dfs(x, y)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    self.res = max(self.res, self.cnt)
                    self.cnt = 0
        return self.res

    def isValid(self, x, y, m, n):
        return x>=0 and x<m and y>=0 and y<n

so = Solution()
grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,1,1,0,1,0,0,0,0,0,0,0,0],
        [0,1,0,0,1,1,0,0,1,0,1,0,0],
        [0,1,0,0,1,1,0,0,1,1,1,0,0],
        [0,0,0,0,0,0,0,0,0,0,1,0,0],
        [0,0,0,0,0,0,0,1,1,1,0,0,0],
        [0,0,0,0,0,0,0,1,1,0,0,0,0]]
result = so.maxAreaOfIsland(grid)
print(result)
assert result==6