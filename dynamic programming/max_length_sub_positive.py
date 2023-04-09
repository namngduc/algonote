from typing import List

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        i, ans = 0, float("-inf")
        while i < len(nums):
            n_s, n_e, n, p, flag = -1, -1, 0, 0, False
            for j in range(i, len(nums)):
                print(j)
                if nums[j] < 0 and n_s==-1: n_s = j
                if nums[j] > 0: p+=1
                if nums[j] < 0: 
                    n+=1
                    n_e = j
                if nums[j]==0:
                    flag = True 
                    break
            print(n, p , n_s, n_e, ans)
            if n%2==0: ans = max(ans, n+p)
            print(j, i, n_s, n_e)
            # import sys; sys.exit()
            if n%2==1:
                tmp = j-n_s-1 if flag else j-n_s
                ans = max(ans, tmp, n_e - i)
            i=j+1
        # print(n, p , n_s, n_e, ans)
        return ans
        

so = Solution()
nums = [-1,2]
result = so.getMaxLen(nums)
print(result)
assert result == 2
