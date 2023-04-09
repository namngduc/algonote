from typing import List

class Solution:
    def maxSquareSum(self, matrix: List[List[str]])->int:
        m, n = len(matrix), len(matrix[0])
        self.ans = float("-inf")
        def dp(x, y):
            if x>= m or y >= n: return 0
            result = 0
            right = dp(x+1, y)
            up = dp(x, y+1)
            diagonal = dp(x+1, y+1)
            if matrix[x][y] == "1":
                result = 1+min(right, up , diagonal)
            self.ans = max(result, self.ans)
            return result
        dp(0, 0)
        return self.ans**2

so = Solution()
matrix = [["0", "1", "0", "0"], ["0", "1", "1", "1"], ["1", "1", "1", "1"], ["0", "0", "1", "0"]]
result = so.maxSquareSum(matrix)
print(result)
assert result == 4
