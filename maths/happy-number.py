class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n not in seen:
            seen.add(n)
            n = sum([int(i)**2 for i in str(n)])
            # print(f"n: {n}")
        return n == 1
