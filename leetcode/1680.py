class Solution:
    def concatenatedBinary(self, n: int) -> int:
        res = 0
        MOD = 1000000007
        for i in range(1, n+1):
            # print(self.calNumBit(i))
            length = self.calNumBit(i)
            res = (res << length) + i
        return res % MOD
    
    def calNumBit(self, n):
        i = 0
        while n > 0:
            n //=2
            i+=1
        return i


if __name__ == "__main__":
    so = Solution()
    n = 100000
    res = so.concatenatedBinary(n)
    print(res)