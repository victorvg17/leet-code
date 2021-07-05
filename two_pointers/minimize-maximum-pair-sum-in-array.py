
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(nums)
        st, end = 0, n-1
        res = 0
        while st < end:
            res = max(res, nums[st] + nums[end])
            st += 1
            end -= 1
        return res
