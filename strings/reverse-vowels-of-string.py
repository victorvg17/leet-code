class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        n = len(s)
        if n == 1:
            return s
        s = list(s)
        start, stop = 0, n-1
        while start < stop:
            while start < stop and s[start] not in vowels:
                start += 1
            while start < stop and s[stop] not in vowels:
                stop -= 1
            s[start], s[stop] = s[stop], s[start]
            start += 1
            stop -= 1
        s = "".join(s)
        return str(s)
