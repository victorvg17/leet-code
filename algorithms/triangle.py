
class Solution:
    def make_input_like(self, tri):
        inf = float('inf')
        min_len = []
        for i in range(len(tri)):
            row_item = []
            for j in range(len(tri[i])):
                row_item.append(inf)
            min_len.append(row_item)
        return min_len
    
    def minimumTotal(self, tri: List[List[int]]) -> int:
        n = len(tri)
        min_len = self.make_input_like(tri)
        min_len[-1] = tri[-1]
        for i in range(n-2, -1, -1):
            for j in range(0, len(tri[i])):
                min_len[i][j] = min(min_len[i+1][j], min_len[i+1][j+1]) \
                                    + tri[i][j]
        return min_len[0][-1]
        
