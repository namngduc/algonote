from typing import List

class Solution:
    def minimumAbsDifference(self, nums: List[int]) -> List[List[int]]:
        minEle = min(nums)
        maxEle = max(nums)
        line = [0]*(maxEle - minEle + 1)
        shift = minEle
        for i in range(len(nums)):
            index = nums[i] - shift
            line[index] += 1
        prev, curr = shift, 0
        minDiff = float("inf")
        res = []
        for i in range(1, len(line)):
            if line[i] == 0: continue
            curr = i + shift
            currentDiff = curr - prev
            if currentDiff > minDiff:
                prev = curr
            if currentDiff == minDiff:
                res.append([prev, curr])
                prev = curr
            if currentDiff < minDiff:
                minDiff = currentDiff
                res = []
                res.append([prev, curr])
                prev = curr
        return res

so = Solution()
# arr = [3,8,-10,23,19,-4,-14,27]
arr = [-2, 5, -5, 3, 1, 4]
print(so.minimumAbsDifference(arr))

