from typing import List

class Solution:
    def intervalsIntersection(self, A: List[List[int]], B: List[List[int]])->List[List[int]]:
        res = []
        i, j = 0, 0
        while i < len(A) and j < len(B):
            a1, a2 = A[i][0], A[i][1]
            b1, b2 = B[j][0], B[j][1]
            if a2 >= b1 and b2 >= a1:
                res.append([max(a1, b1), min(a2, b2)])
            if b2 < a2:
                j+=1
            else:
                i+=1
        return res
    
so = Solution()
A = [[0,2],[5,10],[13,23],[24,25]]
B = [[1,5],[8,12],[15,24],[25,26]]
result = so.intervalsIntersection(A, B)
assert result == [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]