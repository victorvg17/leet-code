class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        out = []
        if len(S) == 0:
            return S
        s_map = {}
        for pos, letter in enumerate(S):
            s_map[letter] = pos
        print(s_map)
        left, right = 0,0
        
        for pos, letter in enumerate(S):
            right = max(right, s_map[letter])
            if right == pos:
                out.append(right-left+1)
                left = pos+1
        return out
        