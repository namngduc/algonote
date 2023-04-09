from typing import List
import sys
# print(sys.getrecursionlimit())
# sys.setrecursionlimit(10000)

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        memo = [-1]*len(nums)
        self.cnt = 0
        def dp(i):
            if i>=len(nums):
                return 0
            if i < 2:
                return dp(i+1)
            if memo[i]!=-1: return memo[i]
            res = 0
            if nums[i-1]-nums[i-2] == nums[i]-nums[i-1]:
                res = 1 + dp(i+1)
            else:
                dp(i+1)
            memo[i] = res
            self.cnt += res
            return res
        dp(0)
        return self.cnt
        # if len(nums) < 3: return 0
        # dp = [0]*len(nums)
        # if nums[2] - nums[1] == nums[1] - nums[0]:
        #     dp[2] = 1
        # for i in range(3, len(nums)):
        #     if nums[i]-nums[i-1]==nums[i-1]-nums[i-2]:
        #         dp[i] = dp[i-1]+1
        # return sum(dp)
             

    def checkValid(self, lis):
        diff = lis[1]-lis[0]
        for i in range(2, len(lis)):
            if lis[i]-lis[i-1]!=diff:
                return False
        return True


so = Solution()
nums = [1, 2, 3, 4]
result = so.numberOfArithmeticSlices(nums)
print(result)