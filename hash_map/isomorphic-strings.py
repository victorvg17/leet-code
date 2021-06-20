class Solution:
    def isIsomorphic(self, inp: str, targ: str) -> bool:
        inp_d = {}
        targ_d = {}
        for i, (s, t) in enumerate(zip(inp, targ)):
            inp_d[s] = inp_d.get(s, []) + [i]
            targ_d[t] = targ_d.get(t, []) + [i]
            
        return list(inp_d.values()) == list(targ_d.values())
