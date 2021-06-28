
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        # d = {i: 0 for i in range(0, n+1)}
        # for i in range(0, n):
        #     d[nums[i]] = d.get(nums[i], 0) + 1
        # for k in d:
        #     if d[k] == 0:
        #         return k
        miss_num =  n*(n+1)/2 - sum(nums)
        return int(miss_num)
