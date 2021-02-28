class Solution:
    def maximalSquare(self, mat: List[List[str]]) -> int:
        rows = len(mat)
        if rows == 0:
            return rows
        cols = len(mat[0])
        
        dp = [[0] * (cols) for i in range(rows)]
        for j in range(cols):
            dp[0][j] = int(mat[0][j]) # fill first row
        for i in range(rows):
            dp[i][0] = int(mat[i][0]) # fill first col
        
        for i in range(1, rows):
            for j in range(1, cols):
                if mat[i][j] == "1":
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j-1], dp[i-1][j]) + 1
        max_sides = map(max, dp)
        max_side = max(max_sides)
        return max_side * max_side
