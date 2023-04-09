from typing import List
from collections import defaultdict

class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        n = len(arr)
        pref, suf, ans = [0]*n, [0]*n, [0]*n
        aDict = dict()
        # aDict = defaultdict(list)
        for i in range(len(arr)):
            aDict[arr[i]] = aDict.get(arr[i], []) + [i]
        for val in aDict.values():
            for i in range(1, len(val)):
                pref[val[i]] = pref[val[i-1]] + i*(val[i] - val[i-1])
        for val in aDict.values():
            for i in range(len(val)-2, -1, -1):
                suf[val[i]] = suf[val[i+1]] + (len(val)-1-i)*(val[i+1]-val[i])
        for i in range(n):
            ans[i] = (pref[i] + suf[i])
        return ans
    
so = Solution()
arr = [2,1,3,1,2,3,3]
result = so.getDistances(arr)
print(result)
assert result == [4,2,7,2,4,4,5]