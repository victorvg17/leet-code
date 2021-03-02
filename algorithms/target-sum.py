
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        self.mem = {} # key:(index, curr_sum), value: num_ways
        self.nums = nums
        self.target = S
        index = len(nums) - 1
        curr_sum = 0
        return self.dp(index, curr_sum)
        
    def dp(self, index: int, curr_sum: int) -> int:
        if (index, curr_sum) in self.mem:
            return self.mem[(index, curr_sum)]
        if index < 0 and curr_sum == self.target:
            return 1
        if index < 0:
            return 0
        
        positive = self.dp(index-1, curr_sum + self.nums[index-1])
        negative = self.dp(index-1, curr_sum - self.nums[index-1])
        self.mem[(index, curr_sum)] = positive + negative
        return self.mem[(index, curr_sum)]
