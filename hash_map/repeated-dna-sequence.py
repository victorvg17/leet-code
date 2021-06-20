
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        res = {}
        s_len = 10
        for i in range(0, n - s_len + 1):
            sub_str = s[i:i+10]
            res[sub_str] = res.get(sub_str, 0) + 1
        out = []
        for k in res:
            if res[k] >= 2:
                out.append(k)
        return out
