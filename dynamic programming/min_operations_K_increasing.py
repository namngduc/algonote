from typing import List

class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        ans = 0
        for i in range(k):
            sub_nums = arr[i::k]
            ans += (len(sub_nums) - self.longestIncreaseSub(sub_nums))
        return ans
        
    def longestIncreaseSub(self, nums):
        top = [-1]*len(nums)
        piles = 0

        for i in range(len(nums)):
            poker = nums[i]
            left, right = 0, piles
            while left < right:
                mid = left + (right-left)//2
                if top[mid] > poker:
                    right = mid
                elif top[mid] <= poker:
                    left = mid + 1
                # else:
                #     right = mid
            if left == piles:
                piles += 1
            top[left] = poker
        return piles

so = Solution()
arr = [12,6,12,6,14,2,13,17,3,8,11,7,4,11,18,8,8,3]
# arr = [4,1,5,2,6,2]
# arr = [5,4,3,2,1]
k = 1
print(so.kIncreasing(arr, k))
assert so.kIncreasing(arr, k) == 12
