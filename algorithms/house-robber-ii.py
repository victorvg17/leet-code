
class Solution:
    def rob_section(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0 for j in range(2)] for i in range(n)]
        dp[0][0] = 0
        dp[0][1] = nums[0]
        for i in range(1, n, 1):
            dp[i][1] = max(dp[i-1][0] + nums[i], dp[i-1][1])
            dp[i][0] = dp[i-1][1]
        return max(dp[n-1][0], dp[n-1][1])
    
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return n
        if n == 1:
            return nums[n-1]
        ret = max(self.rob_section(nums[:-1]),
                  self.rob_section(nums[1:]))
        return ret
