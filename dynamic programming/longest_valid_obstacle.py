from typing import List

class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        res = []
        top = [-1]*len(obstacles)
        piles = 0
        for i in range(len(obstacles)):
            poker = obstacles[i]
            left, right = 0, piles
            while left < right:
                mid = left + (right - left)//2
                if top[mid] > poker:
                    right = mid
                elif top[mid] <= poker:
                    left = mid + 1
            res.append(left+1)
            if left == piles:
                piles += 1
            top[left] = poker
        return res
        
                
so = Solution()
obstacles = [3,1,5,6,4,2]
result = so.longestObstacleCourseAtEachPosition(obstacles)
print(result)
assert result == [1,1,2,3,2,2]