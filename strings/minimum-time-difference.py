class Solution:
    def convert(self, time: str) -> int:
        return int(time[:2])*60 + int(time[3:])
    def findMinDifference(self, A: List[str]) -> int:
        A = list(map(self.convert, A))
        A.sort()
        min_vals = [(y - x)%(24*60) for x,y in zip(A, A[1:] + A[:1])]
        return min(min_vals)
