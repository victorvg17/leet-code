class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {} # key:num, vals: indexes
        for i, n in enumerate(nums):
            if n in d.keys():
                if i - d[n] <= k:
                    return True
            d[n] = i
        return False