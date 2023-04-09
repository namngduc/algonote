# You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
# Two sightseeing spots i and j have a distance j - i between them.
# The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: 
# the sum of the values of the sightseeing spots, minus the distance between them.
# Return the maximum score of a pair of sightseeing spots.
from typing import List

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        # ans = float("-inf")
        # for i in range(len(values)):
        #     for j in range(i+1, len(values)):
        #         ans = max(ans, values[i] + values[j] + i - j)
        # return ans
        res, preIndex = float("-inf"), 0
        for i in range(1, len(values)):
            res = max(res, values[preIndex] + preIndex + values[i] - i)
            if (preIndex + values[preIndex]) < values[i] + i:
                preIndex = i
        return res


so = Solution()
values = [1,2]
# values = [8,1,5,2,6]
result = so.maxScoreSightseeingPair(values)
print(result)
assert result == 11