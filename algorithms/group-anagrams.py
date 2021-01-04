from collections import defaultdict
class Solution:
    def isAnagram(self, s1, s2) -> bool:
        return sorted(s1) == sorted(s2)
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        output = []
        d = defaultdict(list)
        if strs is None:
            return [[]]
        elif len(strs) == 1:
            return [strs]
        else:
            for s in strs:
                key = "".join(sorted(s))
                d[key].append(s)
            for key, value in d.items():
                output.append(value)
        return output
        
        
        