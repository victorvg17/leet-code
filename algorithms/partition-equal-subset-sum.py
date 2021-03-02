class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False
        target = sum(nums)/2
        
        sums = set([0])
        
        for num in nums:
            sum_num = []
            for s in sums:
                if s + num == target:
                    return True
                elif s + num < target:
                    sum_num.append(s + num)
            sums.update(sum_num)
        return False
