
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        rnr = uniq = 0
        n = len(nums)
        while rnr < n-1:
            if nums[rnr] != nums[rnr + 1]:
                uniq += 1
                nums[uniq] = nums[rnr + 1]
            rnr += 1
        return uniq+1
