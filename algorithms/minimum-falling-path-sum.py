class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        if len(matrix) == 0:
            return 0
        m = len(matrix)
        n = len(matrix[0])
        if m == 1 or n == 1:
            return min(matrix[0])
        
        for i in range(1, m):
            for j in range(0, n):
                if j == 0:
                    dp = min(matrix[i-1][j], matrix[i-1][j+1])
                elif j == m-1:
                    dp = min(matrix[i-1][j-1], matrix[i-1][j])
                else:
                    dp = min(matrix[i-1][j-1], matrix[i-1][j], matrix[i-1][j+1])
                matrix[i][j] += dp
        return min(matrix[m-1])
