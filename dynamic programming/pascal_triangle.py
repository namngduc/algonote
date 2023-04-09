from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # if numRows == 1: return [[1]]
        # if numRows == 2: return [[1], [1, 1]]
        # dp = [[1], [1, 1]]

        # for currRow in range(2, numRows):
        #     curr = []
        #     for j in range(currRow + 1):
        #         if j == 0: curr += [1]
        #         elif j == currRow: curr += [1]
        #         else:
        #             curr.append(dp[currRow-1][j-1] + dp[currRow-1][j])
        #     dp.append(curr)
        # return dp
        # if numRows == 0: return [1]
        dp = []
        def dfs(nums):
            if nums == 1: return dp.append([1])
            dfs(nums-1)
            prevList = dp[nums-2]
            curr = []
            for i in range(len(prevList)):
                if i == 0: curr.append(1)
                if i > 0: curr.append(prevList[i-1] + prevList[i])
                if i == len(prevList)-1: curr.append(1)
            dp.append(curr)
            return dp
        dfs(numRows+1)
        return dp



so = Solution()
nums = 4
print(so.generate(nums)) 
