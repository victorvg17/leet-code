
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        lefts = [1 for i in range(n)]
        rights = [1 for i in range(n)]
        ret = [1 for i in range(n)]
        # fill the lefts
        l = 1
        for i in range(1, n):
            l = l*nums[i-1]
            lefts[i] = l

        # fill the rights
        r = 1
        for i in range(n-2, -1, -1):
            r = r*nums[i+1]
            rights[i] = r
        
        for i, (l,r) in enumerate(zip(lefts, rights)):
            ret[i] = l*r
        return ret
