from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sums = sum(nums)
        if sums%2: return False
        sums = sums//2
        def dp(i, j):
            if j==0: return True
            if i==0: return False
            if j < nums[i-1]: return dp(i-1, j)
            return dp(i-1, j) or dp(i-1, j-nums[i-1])
        return dp(len(nums)-1, sums)

so = Solution()
nums = [1, 5, 11, 5]
assert so.canPartition(nums)==True