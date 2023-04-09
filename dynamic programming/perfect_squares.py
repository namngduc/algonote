from typing import Deque, List
import math
from collections import deque

class Solution:
    def perfectSquares(self, n: int)-> int:
        # nums = [i*i for i in range(1, int(math.sqrt(n)+1))]
        # def dp(amount):
        #     if amount == 0: return 0
        #     if amount < 0: return -1
        #     res = float("inf")
        #     for num in nums:
        #         subproblem = dp(amount-num)
        #         if subproblem == -1: continue
        #         res = min(res, 1+subproblem)
        #     return res
        # return dp(n)
        nums = [i*i for i in range(1, int(math.sqrt(n)+1))]
        q = deque([n])
        cnt = 0
        while q:
            cnt += 1
            tmp = deque()
            for i in range(len(q)):
                x = q[i]
                for y in nums:
                    if x==y:
                        return cnt
                    if x < y:
                        break
                    tmp.append(x-y)
            q = tmp


so = Solution()
n = 12
result = so.perfectSquares(n)
print(result)
assert result==3
