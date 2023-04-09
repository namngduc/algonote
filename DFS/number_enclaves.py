from typing import List

class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for i in range(m):
            if grid[i][0] == 1:
                self.dfs(i, 0, grid, m, n)
            if grid[i][n-1] == 1:
                self.dfs(i, n-1, grid, m, n)
        for j in range(n):
            if grid[0][j] == 1:
                self.dfs(0, j, grid, m, n)
            if grid[m-1][j] == 1:
                self.dfs(m-1, j, grid, m, n)
        # print(grid)
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    cnt += 1
                    # self.dfs(i, j, grid, m, n)
        return cnt

    def dfs(self, i, j, grid, m, n):
        grid[i][j] = 0
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for dir in dirs:
            x = i + dir[0]
            y = j + dir[1]
            if self.isValid(x, y, m, n) and grid[x][y] == 1:
                self.dfs(x, y, grid, m, n)

    def isValid(self, x, y, m, n):
        return x>=0 and x<m and y>=0 and y<n 


so = Solution()
grid = [[0,0,0,0],
        [1,0,1,0],
        [0,1,1,0],
        [0,0,0,0]]
result = so.numEnclaves(grid)
print(result)
assert result == 3