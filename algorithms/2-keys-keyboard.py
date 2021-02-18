
class Solution:
    def minSteps(self, n: int) -> int:
        dp = [0]*(n+1)
        for i in range(2, n+1):
            # worst case solution
            dp[i] = i
        for i in range(2, n+1):
            for j in range(i//2, 1, -1):
                if i%j == 0:
                    dp[i] = dp[j] + int(i/j)
                    # check only for the maximum value below i/2
                    break
        return dp[n]
