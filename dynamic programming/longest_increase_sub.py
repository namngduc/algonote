from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1]*len(nums)
        for i in range(len(nums)):
            for j in range(i+1):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    
    def LIS_binarysearch(self, nums: List[int]) -> int:
        # top = [-1]*len(nums)
        # piles = 0

        # for i in range(len(nums)):
        #     poker = nums[i]
        #     left, right = 0, piles
        #     while left < right:
        #         mid = left + (right-left)//2
        #         if top[mid] > poker:
        #             right = mid
        #         elif top[mid] < poker:
        #             left = mid + 1
        #         else:
        #             right = mid
        #     if left == piles:
        #         piles += 1
        #     top[left] = poker
        # return piles
        sub = []
        for num in nums:
            if not sub or sub[-1] < num:
                sub.append(num)
            else:
                left, right = 0, len(sub)-1
                while left < right:
                    mid = left + (right - left)//2
                    if sub[mid] > num:
                        right = mid
                    elif sub[mid] <= num:
                        left = mid + 1
                sub[left] = num
        return len(sub)

so = Solution()
# nums = [10,9,2,5,3,7,101,18]
nums = [7,7,7,7,7,7,7]
# assert so.lengthOfLIS(nums)==4
print(so.LIS_binarysearch(nums))