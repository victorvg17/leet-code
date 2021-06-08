class Solution:
    def numSquares(self, n: int) -> int:
        if n == 0:
            return n
        INT_MAX = 2147483647
        cps = [INT_MAX] * (n+1)
        cps[0] = 0
        for i in range(1, n+1):
            j = 1
            while j*j <= i:
                cps[i] = min(cps[i], cps[i-j*j] + 1)
                j += 1
        return cps[-1]
