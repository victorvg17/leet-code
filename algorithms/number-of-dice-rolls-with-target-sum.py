class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        mem = {}
        
        def dp(d: int, target: int) -> int:
            if d == 0:
                return 0 if target > 0 else 1
            if (d, target) in mem:
                return mem[(d, target)]
            to_return = 0
            for i in range(max(0, target - f), target):
                to_return += dp(d-1, i)
            mem[(d, target)] = to_return
            return to_return
        
        return dp(d, target) % (10**9 + 7)
