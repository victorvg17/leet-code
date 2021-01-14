class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0:
            return 0
        s = s.strip()
        return len(s.split(" ")[-1])