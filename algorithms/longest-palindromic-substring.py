class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 0:
            return n
        dp = [[0 for i in range(n)] for j in range(n)]
        max_len = 0
        start, end = 0, 0
        for i in range(n-1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j-i+1 <= 2 or dp[i+1][j-1] != 0):
                    if i == n-1 or j == n-1:
                        dp[i][j] = j-i+1
                    else:
                        dp[i][j] = 2 + dp[i+1][j-1]
                    if (j-i+1) > max_len:
                        max_len = j-i+1
                        start = i
                        end = j
        return s[start:start+max_len]
