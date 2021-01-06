class Solution:
    def swap_columns(self, matrix: List[List[int]]) -> None:
        R, C = len(matrix), len(matrix)
        for j in range(0, C//2):
            for i in range(0, R):
                t = matrix[i][j]
                matrix[i][j] = matrix[i][C-j-1]
                matrix[i][C-j-1] = t
    def transpose(self, matrix: List[List[int]]) -> None:
        R = len(matrix)
        # print(R)
        for i in range(R):
            for j in range(i, R):
                t = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = t
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        self.transpose(matrix)
        self.swap_columns(matrix)
        