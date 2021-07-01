
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        d = {i:0 for i in range(0,3)} # n: freq
        for n in nums:
            d[n] += 1
        
        idx = 0
        for k in d:
            for j in range(d[k]):
                nums[idx] = k
                idx += 1
