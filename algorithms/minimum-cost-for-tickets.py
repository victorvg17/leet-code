dp = [-1]*367

class Solution:
    def sub_problem(self, days: List[int], costs: List[int], si: int)->int:
        #global dp
        global dp
        n = len(days)
        if si >= n:
            return 0
        
        if dp[si] != -1:
            return dp[si]
        
        cost_day = costs[0] + self.sub_problem(days, costs, si+1)
        i = si
        while i < n and days[i] < days[si]+7:
            i += 1
        cost_week = costs[1] + self.sub_problem(days, costs, i)
        i = si
        while i < n and days[i] < days[si]+30:
            i += 1
        cost_month = costs[2] + self.sub_problem(days, costs, i)
        
        dp[si] = min(cost_day, cost_week, cost_month)
        return dp[si]
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        return self.sub_problem(days, costs, 0)
