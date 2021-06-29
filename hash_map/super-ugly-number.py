
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ug = [1]
        idxs = {p: 0 for p in primes}
        
        while len(ug) < n:
            for p in primes:
                while p*ug[idxs[p]] <= ug[-1]:
                    idxs[p] += 1
                    
            app_val = min([p*ug[idxs[p]] for p in primes])
            ug.append(app_val)
        return ug[-1]
        
