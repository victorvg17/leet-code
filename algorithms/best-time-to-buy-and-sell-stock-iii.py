class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        T_i20, T_i10 = 0, 0
        T_i21, T_i11 = float('-inf'), float('-inf')
        for p in prices:
            T_i20 = max(T_i20, T_i21 + p)
            T_i21 = max(T_i21, T_i10 - p)
            T_i10 = max(T_i10, T_i11 + p)
            T_i11 = max(T_i11, -p)
        return T_i20
