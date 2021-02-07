
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # if len(cost) == 0:
        #     return 0
        if len(cost) <=2:
            return min(cost)
        s = len(cost)
        min_cost = [0]*s
        min_cost[s-1]=cost[s-1]
        min_cost[s-2]=cost[s-2]
        for i in range(s-3, -1, -1):
            min_cost[i] = min(cost[i]+min_cost[i+1], cost[i]+min_cost[i+2])
        min_val = min(min_cost[0], min_cost[1])
        # print(f"min cost: {min_val}")
        return min_val
