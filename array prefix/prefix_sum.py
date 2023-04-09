from typing import List
from collections import defaultdict

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # prefix = [ _ for _ in range(len(nums)+1)]
        # ans = 0
        # prefix[0] = 0
        # for i in range(len(nums)):
        #     prefix[i+1] = nums[i] + prefix[i]
        # for i in range(1, len(prefix)):
        #     for j in range(i):
        #         if (prefix[i] - prefix[j] == k):
        #             ans += 1
        # return ans
        hashSum = dict()
        hashSum[0] = 1
        ans, sum_i = 0, 0
        for i in range(len(nums)):
            sum_i += nums[i]
            sum_j = sum_i - k
            if sum_j in hashSum:
                ans += hashSum[sum_j]
            hashSum[sum_i] = hashSum.get(sum_i, 0) + 1

        return ans, hashSum

so = Solution()
nums, k = [3, 5, 2, -2, 4, 1], 5
res, index = so.subarraySum(nums, k)
print(res)
# assert res == 2
print(index)