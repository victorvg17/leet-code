
class Solution:
    def maxArea(self, h: List[int]) -> int:
        n = len(h)
        i, j = 0, len(h) - 1
        water = 0
        while i < j:
            water = max(water, (j-i)*min(h[j], h[i]))
            if h[i] <= h[j]:
                i += 1
            else:
                j -= 1
        return water
