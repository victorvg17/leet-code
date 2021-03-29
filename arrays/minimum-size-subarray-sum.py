class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        stop = 0
        start = 0
        min_len = float('inf')
        sums = 0
        for stop in range(n):
            sums += nums[stop]
            while sums >= target:
                min_len = min(min_len, stop-start+1)
                sums -= nums[start]
                start += 1
        if min_len == float('inf'):
            return 0
        else:
            return min_len
