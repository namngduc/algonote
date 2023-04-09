from typing import List

class Solution:
    def merge(self, intervals: List[List[int]])-> List[List[int]]:
        res = []
        intervals.sort(key=lambda ints: ints[0])
        res.append(intervals[0])

        for i in range(1, len(intervals)):
            curr = intervals[i]
            last = res[-1]
            if curr[0] <= last[1]:
                last[1] = max(curr[1], last[1])
            else:
                res.append(curr)
        return res

so = Solution()
intervals = [[1,3],[2,6],[8,10],[15,18]]
result = so.merge(intervals) 
assert result == [[1,6],[8,10],[15,18]]