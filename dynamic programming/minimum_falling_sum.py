from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        for i in range(1, m):
            for j in range(n):
                matrix[i][j] += min(matrix[i-1][k] for k in [j-1, j, j+1] if 0 <= k < n)
        return min(matrix[m-1])
so = Solution()
matrix = [[2,1,3],[6,5,4],[7,8,9]]
result = so.minFallingPathSum(matrix)
print(result)
assert result == 13