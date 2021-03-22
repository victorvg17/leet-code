class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        max_profit, min_price = 0, float('inf')
        for p in prices:
            min_price = min(p, min_price)
            profit = p - min_price
            max_profit = max(profit, max_profit)
        return max_profit

# DP solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        T_10 = 0
        T_11 = -prices[0]
        for p in prices:
            T_10 = max(T_10, T_11 + p)
            T_11 = max(T_11, -p)
        return T_10

# best-time-to-buy-and-sell-stock-ii
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        T_ik0 = 0
        T_ik1 = float('-inf')
        for p in prices:
            T_ik0 = max(T_ik0, T_ik1 + p)
            T_ik1 = max(T_ik1, T_ik0 - p)
        return T_ik0
