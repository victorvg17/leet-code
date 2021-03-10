
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        if m == 0 or n == 0:
            return max(m, n)
        
        dp = [[0 for j in range(m+1)] for i in range(n+1)]
        word1 = str(0) + word1
        word2 = str(0) + word2
        for j in range(m+1):
            dp[0][j] = len(word2[:j])
        for i in range(1, n+1):
            dp[i][0] = len(word1[:i])
            for j in range(1, m+1):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]) + 1
        return dp[n][m]
