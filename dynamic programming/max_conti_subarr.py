from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # res = float("-inf")
        # n = len(nums)
        # def maxSub(i, nums):
        #     currMax, max_sub = nums[i%n], nums[i%n]
        #     for j in range(i+1, n+i):
        #         currMax = max(nums[j%n], currMax + nums[j%n])
        #         max_sub = max(currMax, max_sub)
        #     return max_sub
        # for i in range(n):
        #     res = max(res, maxSub(i, nums))
        # return res
        max_sum = max(nums)
        if max_sum < 0: return max_sum
        sum_nums = sum(nums)
        negative_nums = [-n for n in nums]
        minimum_sum = self.kandane(negative_nums)
        return max(self.kandane(nums), sum_nums + minimum_sum)

    # def kandane(self, arr):
    #     currSum, maxSum = arr[0], arr[0]
    #     for i in range(1, len(arr)):
    #         currSum = max(arr[i], currSum + arr[i])
    #         maxSum = max(maxSum, currSum)
    #     return maxSum
    def kandane(self, arr):
        self.ans = float("-inf")
        def dp(i):
            if i >= len(arr):
                return 0
            tmp = max(arr[i], arr[i] + dp(i+1))
            self.ans = max(self.ans, tmp)
            return tmp
        dp(0)
        return self.ans

so = Solution()
nums = [-2, -3, 4, -1, -2, 1, 5, -3]
import time
start = time.time()
result = so.maxSubarraySumCircular(nums)
print("Time: {:0.4f} s".format(time.time() - start))
print(result)
assert result==10