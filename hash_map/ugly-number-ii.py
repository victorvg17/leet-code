
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ug = [1]
        i2 = i3 = i5 = 0
        while len(ug) < n:
            while ug[i2]*2 <= ug[-1]:
                i2 += 1
            while ug[i3]*3 <= ug[-1]:
                i3 += 1
            while ug[i5]*5 <= ug[-1]:
                i5 += 1
            ug.append(min(ug[i2]*2, ug[i3]*3, ug[i5]*5))
        return ug[-1]
        
