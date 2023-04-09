from typing import List

class Solution:
    def numDistinctIslands(self, grid: List[List[int]])-> int: 
        hashSet = set()
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    sb = []
                    self.dfs(i, j, grid, sb, "666")
                    tmp = ",".join(sb)
                    hashSet.add(tmp)
        print(hashSet)
        return len(hashSet)

    def dfs(self, i, j, grid, sb, dir):
        m, n = len(grid), len(grid[0])
        if i<0 or i>=m or j<0 or j>=n:
            return 
        if grid[i][j] == 0:
            return
        grid[i][j] = 0
        sb.append(dir)
        self.dfs(i-1, j, grid, sb, "1")  # Up
        self.dfs(i+1, j, grid, sb, "2")  # Down
        self.dfs(i, j-1, grid, sb, "3")  # Left
        self.dfs(i, j+1, grid, sb, "4")  # Right
        sb.append("-" + dir)

so = Solution()
grid = [[1, 1, 0, 1, 1],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1],
        [1, 1, 0, 1, 1]]
result = so.numDistinctIslands(grid)
assert result == 2