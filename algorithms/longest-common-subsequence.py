class Solution:
    def print_mat(self, dp):
        for r in dp:
            print(r)
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1) # rows
        m = len(text2) # cols
        dp = [[0 for j in range(m+1)] for i in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, m+1):
                if text2[j-1] == text1[i-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        return dp[n][m]
