
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0
        i = len(a)-1
        j = len(b)-1
        a, b = list(a), list(b)
        while i>=0 or j>=0 or carry > 0:
            c_sum = 0
            if i >= 0:
                c_sum += int(a[i])
            if j >= 0:
                c_sum += int(b[j])
            if carry > 0:
                c_sum += carry
            res += str(c_sum % 2)
            carry = c_sum // 2
            i -= 1
            j -= 1
        return res[::-1]
