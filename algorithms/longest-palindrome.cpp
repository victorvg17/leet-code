def longestPalindrome(s: str) -> str:
    res_len = 0
    res_string = ""
    # for palindrome string odd
    for i in range(len(s)):
        l, r = i, i
        while l >= 0 and r < len(s) and s[l] == s[r]:
            if res_len < r-l+1:
                res_len = r-l+1
                res_string = s[l:r+1] #includes r-th character too
            l -= 1
            r += 1
    # for palindrome string even
    for i in range(len(s)):
        l, r = i, i+1
        while l >= 0 and r < len(s) and s[l] == s[r]:
            if res_len < r-l+1:
                res_len = r-l+1
                res_string = s[l:r+1] #includes r-th character too
            l -= 1
            r += 1
    return res_string
