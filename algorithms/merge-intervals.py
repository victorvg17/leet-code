class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        out = []
        if len(intervals) == 0 or len(intervals) == 1:
            return intervals
        intervals = sorted(intervals, key=lambda item: item[0])
        print(intervals)
        runner = intervals[0]
        for it in intervals:
            if runner[1] >= it[0]:
                runner[1] = max([runner[1], it[1]])
            else:
                out.append(runner)
                runner = it
        out.append(runner)
        return out
                