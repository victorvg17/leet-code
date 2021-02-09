class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if len(grid) == 0:
            return 0
        m = len(grid)
        n = len(grid[0])
        if m == 1 or n == 1:
            return sum(grid[0])
        costs = [ [0]*n for i in range(m) ]
        costs[m-1][n-1] = grid[m-1][n-1]
        # update the border-last row and last col values
        for j in range(n-2, -1, -1):
            costs[m-1][j] = grid[m-1][j] + costs[m-1][j+1]
        for i in range(m-2, -1, -1):
            costs[i][n-1] = grid[i][n-1] + costs[i+1][n-1]
        
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                print(f"i:{i}, j:{j}")
                mc = min(costs[i+1][j], costs[i][j+1])
                costs[i][j] = mc + grid[i][j]
        
        return costs[0][0]
