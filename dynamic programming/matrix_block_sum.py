# Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

# i - k <= r <= i + k,
# j - k <= c <= j + k, and
# (r, c) is a valid position in the matrix.

from typing import List

class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        A = [[0]*(n+1) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                A[i+1][j+1] = A[i+1][j] + A[i][j+1] - A[i][j] + mat[i][j]
        print(A)
        for i in range(m):
            for j in range(n):
                r1, r2 = max(i-k, 0), min(i+k, m-1) + 1
                c1, c2 = max(j-k, 0), min(j+k, n-1) + 1
                mat[i][j] = A[r1][c1] + A[r2][c2] - A[r1][c2] - A[r2][c1]
        return mat
        # for i in range(m):
        #     for j in range(n):
        #         r = [max(i-k, 0), min(i+k, m-1) + 1]
        #         c = [max(j-k, 0), min(j+k, n-1) + 1]
        #         print("x: ", [i for i in range(r[0], r[1])])
        #         print("y: ", [i for i in range(c[0], c[1])])
        #         A[i][j] = sum(sum(mat[x][y] for y in range(c[0], c[1])) for x in range(r[0], r[1]))
        # return A


so = Solution()
mat = [[1,2,3],[4,5,6],[7,8,9]]
k = 1
result = so.matrixBlockSum(mat, k)
print(result)
assert result == [[12,21,16],[27,45,33],[24,39,28]]