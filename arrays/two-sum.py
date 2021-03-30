
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # n = len(nums)
        d = {} # val: idx
        for i, a in enumerate(nums):
            b = target - a
            if a in d:
                return [i, d[a]]
            else:
                d[b] = i
