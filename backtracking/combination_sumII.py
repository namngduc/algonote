from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        track = []
        self.res = []
        candidates.sort()
        self.backtrack(candidates, 0, track, target)
        return self.res
        
    def backtrack(self, candidates, k, track, remain):
        print(track)
        if remain==0:
            if track in self.res: 
                return
            self.res.append(track.copy())
            return
        if remain < 0:
            return
        for i in range(k, len(candidates)):
            if i > k and candidates[i]==candidates[i-1]: continue
            track.append(candidates[i])
            self.backtrack(candidates, i+1, track, remain-candidates[i])
            track.pop()
        
so = Solution()
candidates = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
target = 12
import time
start = time.time()
result = so.combinationSum2(candidates, target)
print("Time processing : {:0.4f} s".format(time.time() - start))
print(result)