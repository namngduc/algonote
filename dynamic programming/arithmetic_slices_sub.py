from typing import List
from collections import defaultdict

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        # self.cnt = 0
        # def dp(i, curr):
        #     if i==len(nums):
        #         print("Debug: ", curr)
        #         if len(curr) < 3:
        #             return
        #         for i in range(1, len(curr)):
        #             if curr[i]-curr[i-1] != curr[1]-curr[0]:
        #                 return
        #         self.cnt += 1
        #         return
        #     dp(i+1, curr)
        #     curr.append(nums[i])
        #     # print(curr)
        #     dp(i+1, curr)
        #     curr.pop()
        # dp(0, curr=[])
        # return self.cnt
        n = len(nums)
        dp = [defaultdict(int) for _ in range(n)]
        res = 0
        for i in range(1, n):
            for j in range(0, i):
                diff = nums[i] - nums[j]
                dp[i][diff] += dp[j].get(diff, 0) + 1
                res += dp[j][diff]
        for i in range(len(dp)):
            print(i, dp[i])
        return res


so = Solution()
nums = [0,2,2,3,4]
result = so.numberOfArithmeticSlices(nums)
print(result)