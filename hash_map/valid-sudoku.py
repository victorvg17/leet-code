
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = []
        for i in range(9):
            for j in range(9):
                # (c, j), (i, c), (i//3, j//3, c)
                c = board[i][j]
                if c != ".":
                    seen += (c, j), (i, c), (i//3, j//3, c)
        return len(seen) == len(set(seen))
        
