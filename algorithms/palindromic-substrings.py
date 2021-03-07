class Solution:
    def countSubstrings(self, s: str) -> int:
        # if all are unique
        n = len(s)
        if n == 0:
            return n
        dp = [[0 for j in range(n)] for i in range(n)]
        total = 0
        
        for i in range(n-1, -1, -1):
            for j in range(i, n):
                if (s[i] == s[j]) and (j-i+1 <= 2 or dp[i+1][j-1]):
                    dp[i][j] = 1
                    total += 1
        return total
