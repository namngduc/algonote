
class Solution:
    def minimumDistance(self, nums, target, start):
        res = float("inf")
        for idx, v in enumerate(nums):
            if v==target:
                res = min(res, abs(idx - start))
        return res

so = Solution()
nums = [1, 1, 1, 1, 1, 1, 1, 1]
target = 1
start = 0
print(so.minimumDistance(nums, target, start))