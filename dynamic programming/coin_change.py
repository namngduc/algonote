from typing import List
from functools import lru_cache
import sys
from automatic_indentation import AutoIndent

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # @lru_cache(None)
        self.count = 0
        memo = dict()
        def dp(n):
            print(f"n={n}")
            # self.count+=1
            # Solution.printIndent(self.count)
            # sys.stdout.write(f"n={n}\n")
            if n==0:
                # self.count-=1
                # Solution.printIndent(self.count)
                # sys.stdout.write(f" return {0}\n")
                print("return 0")
                return 0
            if n<0:
                # self.count-=1
                # Solution.printIndent(self.count)
                # sys.stdout.write(f" return {-1}\n")
                print("return -1")
                return -1
            if n in memo: return memo[n]
            res = float("inf")
            for coin in coins:
                subproblem = dp(n-coin)
                if subproblem == -1: continue
                res = min(res, dp(n-coin)+1)
            ans = res if res != float("inf") else -1
            memo[n] = ans
            # self.count-=1
            # Solution.printIndent(self.count)
            # sys.stdout.write(f" return {ans}\n")
            print(f"return {ans}")
            return ans
        return dp(amount)
    @staticmethod
    def printIndent(n):
        for _ in range(n):
            sys.stdout.write(" ")
        # print("\n")

so = Solution()
coins, amount = [2, 3, 5], 11
sys.stdout = AutoIndent(sys.stdout)
so.coinChange(coins, amount)