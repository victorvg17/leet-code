class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if A[i-1] == B[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
        max_len = max([max(dp[i]) for i in range(0, m+1)])
        return max_len
