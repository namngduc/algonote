from typing import List

class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        for i in range(m):
            for j in range(n):
                if grid2[i][j]==1 and grid1[i][j] == 0:
                    self.dfs(i, j, grid2, m, n)
                    # grid1[i][j] = 0
        print(grid2)
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 1:
                    cnt += 1
                    self.dfs(i, j, grid2, m, n)
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
grid1 = [[1,1,1,0,0],
         [0,1,1,1,1],
         [0,0,0,0,0],
         [1,0,0,0,0],
         [1,1,0,1,1]]
grid2 = [[1,1,1,0,0],
         [0,0,1,1,1],
         [0,1,0,0,0],
         [1,0,1,1,0],
         [0,1,0,1,0]]

        #  [[1, 1, 1, 0, 0], 
        #   [0, 0, 1, 1, 1], 
        #   [0, 0, 0, 0, 0], 
        #   [1, 0, 0, 0, 0], 
        #   [0, 1, 0, 1, 0]]
result = so.countSubIslands(grid1, grid2)
assert result == 3