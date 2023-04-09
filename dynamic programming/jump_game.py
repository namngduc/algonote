# Jump Game
# Given an integer array nums. Initially positioned at first's index, each element in the array represents maximum jump length. 
# Return true if you can reach the last index, or false otherwise

from typing import List
from functools import lru_cache

# Solution 1: Recursive + memoization. Using dp array instead of @lru_cache can make TLE 
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        @lru_cache(None)
        def dfs(i):
            if i == len(nums)-1: return True
            for n in range(i+1, min(i+nums[i], len(nums)-1)+1):
                if dfs(n):
                    return True
            return False
        return dfs(0)

# Solution 2: Greedy
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump, i = 0, 0
        while i <= maxJump:
            maxJump = max(maxJump, i+nums[i])
            if maxJump >= len(nums)-1: return True
            i+=1
        return False
        
so = Solution()
nums  = [1,0,1, 0]
print(so.canJump(nums))