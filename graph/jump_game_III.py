from typing import List
from collections import defaultdict
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        graph = defaultdict(list)
        for k, v in enumerate(arr):
            if v==0: 
                continue
            u1 = k+v
            u2 = k-v
            if u1 < len(arr):
                graph[k].append(u1)
            if u2 >= 0:
                graph[k].append(u2)
        visited = set()
        self.index = -1
        def dfs(start):
            visited.add(start)
            for u in graph[start]:
                if u not in visited:
                    visited.add(u)
                    if arr[u]==0: self.index=u
                    dfs(u)
        dfs(start)
        return True if self.index != -1 else False
        # stack = [start]
        # visited.add(start)
        # while stack:
        #     node = stack.pop()
        #     # if node in end:
        #     #     return True
        #     for u in graph[node]:
        #         if u not in visited:
        #             visited.add(u)
        #             if arr[u]==0: return True
        #             stack.append(u)
        # return False

so = Solution()
nums = [4,2,3,0,3,1,2]
# nums = [1,0,2,0]
start = 5
print(so.canReach(nums, start))